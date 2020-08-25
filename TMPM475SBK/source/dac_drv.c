/**
 ****************************************************************************
 * @file	 dac_drv.c
 * @brief	 DAC Device Functions.
 * @version  V1.0
 *****************************************************************************
 */
#include "ipdefine.h"

#include "tmpm475_uart.h"

#define DEFINE_APP
#include "dac_drv.h"
#undef	DEFINE_APP

/**
 * @note	DAC IC Control for AD5724.
 *
 */

/*===================================================================*
  Device local functions prototype.
 *===================================================================*/
static void DacLocalWriteInit(TSB_SC_TypeDef* const SCx);


/*===================================================================*
	  Local Variable Definition
 *===================================================================*/
uint32_t DacNo = DAC_MAX_CH;


/*===================================================================*
	  Const Definition
 *===================================================================*/
#define	cDAC_POWERCON	BIT32(0,0,0,0,0,0,0,0, 0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1)
/*                                             | | | | | | | | | | | | | | | | | | | | | | | +----; PUA
                                               | | | | | | | | | | | | | | | | | | | | | | +------; PUB
                                               | | | | | | | | | | | | | | | | | | | | | +--------; PUC
                                               | | | | | | | | | | | | | | | | | | | | +----------; PUD
                                               | | | | | | | | | | | | | | | | | | | +------------; 0
                                               | | | | | | | | | | | | | | | | | | +--------------; TSD
                                               | | | | | | | | | | | | | | | | | +----------------; 0
                                               | | | | | | | | | | | | | | | | +------------------; OCA(R)
                                               | | | | | | | | | | | | | | | +--------------------; OCB(R)
                                               | | | | | | | | | | | | | | +----------------------; OCC(R)
                                               | | | | | | | | | | | | | +------------------------; OCD(R)
                                               | | | | | | | | +-+-+-+-+--------------------------; x
                                               | | | | | +-+-+------------------------------------; 0
                                               | | +-+-+------------------------------------------; REG2,1,0
                                               | +------------------------------------------------; 0
                                               +--------------------------------------------------; R/W
*/



/**
 *********************************************************************************************
 * @brief		D/A initialize.
 *
 * @return		none
 *********************************************************************************************
 */
void init_Dac(void)
{
	SIO_InitTypeDef SIO_DacInit;

	SIO_Enable(DAC_SIO_CH);

	/* Setting SIO port. */
	TSB_PA->FR1 |= ((1 << 4u) | (1 << 5u));
	TSB_PA->CR |= ((1 << 4u) | (1 << 5u));

	/* Setting ~SYNC port */
	TSB_PA->DATA |= (1 << 6u);
	TSB_PA->CR |= (1 << 6u);

	/* Setting LOD port */
	TSB_PA->DATA |= (1 << 7u);
	TSB_PA->CR |= (1 << 7u);

	/*initialize the SIO struct */
	SIO_DacInit.InputClkEdge = SIO_SCLKS_TXDR_RXDF;
	SIO_DacInit.TIDLE = SIO_TIDLE_LAST;
	SIO_DacInit.TXDEMP = SIO_TXDEMP_HIGH;
	SIO_DacInit.EHOLDTime = SIO_EHOLD_FC_2;
	SIO_DacInit.IntervalTime = SIO_SINT_TIME_NONE;
	SIO_DacInit.TransferMode = SIO_TRANSFER_HALFDPX_TX;
	SIO_DacInit.TransferDir = SIO_MSB_FRIST;
	SIO_DacInit.Mode = SIO_ENABLE_TX;
	SIO_DacInit.DoubleBuffer = SIO_WBUF_DISABLE;
	SIO_DacInit.BaudRateClock = SIO_BR_CLOCK_TS0;
	SIO_DacInit.Divider = SIO_BR_DIVIDER_3;

	SIO_Init(DAC_SIO_CH, SIO_CLK_BAUDRATE, &SIO_DacInit);

	DacLocalWriteInit(DAC_SIO_CH);

	NVIC_SetPriority(DAC_IRQ_INTTX, DAC_IRQ_LEVEL); 	/* Interruption level set */
	NVIC_ClearPendingIRQ(DAC_IRQ_INTTX);
	NVIC_EnableIRQ(DAC_IRQ_INTTX);						/* INTTX enable */
}


/**
 *********************************************************************************************
 * @brief		D/A initial output.
 *
 * @param		TSB_SC_TypeDef * const	SCx		Select the sio channel.
 *
 * @return		none
 *********************************************************************************************
 */
static void DacLocalWriteInit(TSB_SC_TypeDef* const SCx)
{
	DAC_SYNC = 0;										/* begin tx */

	NVIC_ClearPendingIRQ(DAC_IRQ_INTTX);
	SCx->BUF = (uint8_t)((cDAC_POWERCON >> 16U) & 0x000000ff);
	while (!NVIC_GetPendingIRQ(DAC_IRQ_INTTX));

	NVIC_ClearPendingIRQ(DAC_IRQ_INTTX);
	SCx->BUF = (uint8_t)((cDAC_POWERCON >> 8U) & 0x000000ff);
	while (!NVIC_GetPendingIRQ(DAC_IRQ_INTTX));

	NVIC_ClearPendingIRQ(DAC_IRQ_INTTX);
	SCx->BUF = (uint8_t)(cDAC_POWERCON & 0x000000ff);
	while (!NVIC_GetPendingIRQ(DAC_IRQ_INTTX));

	DAC_SYNC = 1;										/* end tx */
}


/**
 *********************************************************************************************
 * @brief		D/A data output start.
 *
 * @param		TSB_SC_TypeDef * const	SCx		Select the sio channel.
 *
 * @return		none
 *********************************************************************************************
 */
void DacWriteStart(TSB_SC_TypeDef* const SCx)
{
	if (DacNo >= DAC_MAX_CH)
	{
		DacNo = 0;
		DacWriteContinue(SCx);
	}
}


/**
 *********************************************************************************************
 * @brief		D/A data output continue.
 *
 * @param		TSB_SC_TypeDef * const	SCx		Select the sio channel.
 *
 * @return		none
 *********************************************************************************************
 */
void DacWriteContinue(TSB_SC_TypeDef* const SCx)
{
	static uint16_t data = 0;
	static uint16_t seq = 0;

	if (DacNo < DAC_MAX_CH)
	{
		switch (seq)
		{
			case 0:
				data = DacData[DacNo];
				DAC_SYNC = 1;							/* end tx */
				DAC_SYNC = 0;							/* begin tx */
				SCx->BUF = DacNo;
				seq = 1;
				break;
			case 1:
				SCx->BUF = (data >> 8);
				seq = 2;
				break;
			case 2:
				SCx->BUF = data;
				seq = 0;
				++DacNo;
				break;
			default:
				break;
		}
	}
	else
	{
		DAC_SYNC = 1;									/* end tx */

		/* for synchronization of DAC output */
		/* SYNC H Å® 20ns Å® LDAC L Å® 20ns Å® LDAC H */
#ifndef KEIL_VER
		__no_operation();
		__no_operation();
		__no_operation();
#else
		__nop();
		__nop();
		__nop();
#endif		
		DAC_LDAC = 0;
#ifndef KEIL_VER
		__no_operation();
		__no_operation();
		__no_operation();
#else
		__nop();
		__nop();
		__nop();
#endif		
		DAC_LDAC = 1;
	}
}


/*********************************** END OF FILE ******************************/
