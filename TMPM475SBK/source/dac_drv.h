/**
 ****************************************************************************
 * @file	 dac_drv.h
 * @brief	 DAC Device Functions.
 * @version  V1.0
 *****************************************************************************
 */
#ifndef _DACDRV_H
#define _DACDRV_H

#undef EXTERN
#ifdef DEFINE_APP
#define EXTERN
#else
#define EXTERN  extern
#endif

/*===================================================================*
  Macro Definition
 *===================================================================*/
#define DAC_CLK 				TSB_PA_DATA_PA4
#define DAC_DIO 				TSB_PA_DATA_PA5
#define DAC_SYNC				TSB_PA_DATA_PA6
#define DAC_LDAC				TSB_PA_DATA_PA7

#define DAC_SIO_CH				TSB_SC1
#define DAC_IRQ_INTTX			INTTX1_IRQn
#define DAC_IRQ_LEVEL			INT_DAC_LEVEL

#define DAC_MAX_CH				4				/* MAX channel */


/*===================================================================*
  Definition of variable
 *===================================================================*/
EXTERN	uint16_t	DacData[DAC_MAX_CH];


/*===================================================================*
  Proto Type Definition
 *===================================================================*/
EXTERN	void	init_Dac(void);
EXTERN	void	DacWriteStart(TSB_SC_TypeDef * const SCx);
EXTERN	void	DacWriteContinue(TSB_SC_TypeDef * const SCx);


#undef EXTERN
#endif  /* _DACDRV_H */


/*************************** END OF FILE **************************************/
