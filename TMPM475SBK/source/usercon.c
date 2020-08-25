/**
 ****************************************************************************
 * @file	 usercon.c
 * @brief	 User Control
 * @version  V1.0
 *****************************************************************************
 */
#include <stdlib.h>
#include <stdio.h>

#include "ipdefine.h"
#include "mcuip_drv_ave.h"
#include "D_Para.h"

#include "tmpm475_gpio.h"
#include "tmpm475_adc.h"

#include "tmpm475_uart.h"

#include "dac_drv.h"

#include "nguyen_uart.h"
#include "tmpm475_can_int.h"
#include "nguyen_motor_app.h"


#define DEFINE_APP
#include "usercon.h"
#undef	DEFINE_APP


/*===================================================================*
	  Macro Definition
 *===================================================================*/

/*===================================================================*
	  Local Constant Data Definition
 *===================================================================*/
/* Key settting */
#define P_SW1				TSB_PH_DATA_PH0 				/* SW1 */
#define P_SW2				TSB_PH_DATA_PH1 				/* SW2 */
#define P_SW3				TSB_PH_DATA_PH2 				/* SW3 */
#define P_SW4				TSB_PH_DATA_PH3 				/* SW4 */
#define P_TSW1				TSB_PE_DATA_PE4 				/* TSW1 */
#define P_TSW2				TSB_PE_DATA_PE5 				/* TSW2 */
#define P_TSW3				TSB_PE_DATA_PE6 				/* TSW3 */
#define P_TSW4				TSB_PE_DATA_PE7 				/* TSW4 */

#define cKEY_CHATA_CNT		(20)							/* [cnt] chattering counter for KEY SW */


/* Soft ADC Setting */
#define	cADUNIT_USR			TSB_ADB							/* User ad data ADCUnit */
#define cADCH_VR			ADC_AIN9						/* ADC Channel for VR */
#define cADREG_VR			ADC_REG4						/* Result register No for VR */


/* led setting */
#define LED_EMG				TSB_PA_DATA_PA0 				/* LED1 */
//#define LED_VE			TSB_PA_DATA_PA1 				/* LED2 */
#define LED_STAGE			TSB_PA_DATA_PA2 				/* LED3 */
#define LED_DAC				TSB_PA_DATA_PA3 				/* LED4 */

#define	cFLASH_TYPE1_CYCLE	(1)								/* [s] led flash cycle type1 */
#define	cFLASH_TYPE2_CYCLE	(0.5)							/* [s] led flash cycle type2 */
#define	cFLASH_TYPE3_CYCLE	(0.25)							/* [s] led flash cycle type3 */

#define	cLED_ON				(1)								/* LED ON level */
#define	cLED_OFF			(0)								/* LED OFF level */


/* speed control setting */
#define	cAD_MIN				(0x10)
#define	cAD_MAX				(0xF0)
#define	cSPEED_USER_MIN		(20) 							// [Hz] Min Target speed of motor
#define	cSPEED_USER_MAX		(150) 							// [Hz] Max Target speed of motor


/*===================================================================*
	  Typedef Definition
 *===================================================================*/
typedef struct
{
	uint8_t		select;										/* Dac output select */
	uint8_t		motch;										/* Dac motor ch select */
	uint8_t		datsft0;									/* Dac data shift for data0 */
	uint8_t		datsft1;									/* Dac data shift for data1 */
	uint8_t		datsft2;									/* Dac data shift for data2 */
	uint8_t		datsft3;									/* Dac data shift for data3 */
} dac_t;



#if defined(__CONTROL_MOTOR_CH1)
extern	int32_t	target_spd1;
#endif /* __CONTROL_MOTOR_CH1 */

#if defined(__CONTROL_MOTOR_CH0)
extern	int32_t	target_spd0;
#endif /* __CONTROL_MOTOR_CH0 */


/*===================================================================*
	  Local Variable Definition
 *===================================================================*/
static uint8_t		motor_ready;							/* detect motor stop after startup */

static uint8_t		keydata;								/* Key data */
static uint8_t		keydata_old;							/* Previous Key data */
static sw_t			keyportbuf_old; 						/* Previous Key port data */
static uint8_t		key_chatacnt;							/* Chattering counter for Key */
static sw_t			swdata;									/* toggle sw data */
static sw_t			swportbuf_old; 							/* Previous toggle sw port data */
static uint8_t		sw_chatacnt;							/* Chattering counter for toggle sw */

/* No, ch, sft0, sft1, sft2, sft3 */
 dac_t 		dac = {   0,  1,	0,	  0,	0,	  0 };

static uint16_t		flash_type1_cycle;						/* led flash cycle type1 counter */
static uint16_t		flash_type2_cycle;						/* led flash cycle type2 counter */
static uint16_t		flash_type3_cycle;						/* led flash cycle type3 counter */
static uint8_t		flash_type1;							/* led flash cycle type1 timing */
static uint8_t		flash_type2;							/* led flash cycle type2 timing */
static uint8_t		flash_type3;							/* led flash cycle type3 timing */

/*===================================================================*
	  Local Proto Type Definition
 *===================================================================*/
static void init_Uikey(void);
static void Uikeyscan(void);
static void init_soft_adc(void);
static void init_led(void);
static void led_display(void);

static void user_setting(void);

/**
 *********************************************************************************************
 * @brief		init_user_control
 *
 * @return		none
 *********************************************************************************************
 */
void	init_user_control(void)
{

	init_Uikey();										/* Initial setting of key input */
	init_soft_adc();									/* Initial setting of soft adc */

#if defined(__USE_CHECK_IERROR)
	init_check_id_error();								/* Initial setting of id error control */
#endif /* __USE_CHECK_IERROR */

	init_led();											/* Initial setting of led output */
}

/**
 *********************************************************************************************
 * @brief		user_control
 *
 * @return		none
 *********************************************************************************************
 */
void	user_control(void)
{
	/***** key input *****/
	//Uikeyscan();

	/***** user setting *****/
	user_setting();

	/***** ked output *****/
	led_display();
}


/**
 *********************************************************************************************
 * @brief		Initialize key.
 *
 * @return		none
 *********************************************************************************************
 */
static void init_Uikey(void)
{
	GPIO_SetInputEnableReg(GPIO_PH, GPIO_BIT_0, ENABLE);	/* SW1 */
	GPIO_SetInputEnableReg(GPIO_PH, GPIO_BIT_1, ENABLE);	/* SW2 */
	GPIO_SetInputEnableReg(GPIO_PH, GPIO_BIT_2, ENABLE);	/* SW3 */
	GPIO_SetInputEnableReg(GPIO_PH, GPIO_BIT_3, ENABLE);	/* SW4 */

	GPIO_SetInputEnableReg(GPIO_PE, GPIO_BIT_4, ENABLE);	/* TSW1 */
	GPIO_SetInputEnableReg(GPIO_PE, GPIO_BIT_5, ENABLE);	/* TSW2 */
	GPIO_SetInputEnableReg(GPIO_PE, GPIO_BIT_6, ENABLE);	/* TSW3 */
	GPIO_SetInputEnableReg(GPIO_PE, GPIO_BIT_7, ENABLE);	/* TSW4 */
}

/**
 *********************************************************************************************
 * @brief		keyscan
 *
 * @return		none
 *********************************************************************************************
 */
static void Uikeyscan(void)
{
	sw_t	portbuf;

	*((uint8_t*)&portbuf) = 0xff;							/* low active */
	portbuf.sw1 = P_SW1;
	portbuf.sw2 = P_SW2;
	portbuf.sw3 = P_SW3;
	portbuf.sw4 = P_SW4;

	if (*((uint8_t*)&portbuf) == *((uint8_t*)&keyportbuf_old))
	{
		if (key_chatacnt != 0)
		{
			if (--key_chatacnt == 0)
			{
				keydata = ~(*((uint8_t*)&portbuf));
			}
		}
	}
	else
	{
		*((uint8_t*)&keyportbuf_old) = *((uint8_t*)&portbuf);
		key_chatacnt = cKEY_CHATA_CNT;
	}

	*((uint8_t*)&portbuf) = 0;
	portbuf.sw1 = P_TSW1;
	portbuf.sw2 = P_TSW2;
	portbuf.sw3 = P_TSW3;
	portbuf.sw4 = P_TSW4;

	if (*((uint8_t*)&portbuf) == *((uint8_t*)&swportbuf_old))
	{
		if (sw_chatacnt != 0)
		{
			if (--sw_chatacnt == 0)
			{
				*((uint8_t*)&swdata) = *((uint8_t*)&portbuf);
			}
		}
	}
	else
	{
		*((uint8_t*)&swportbuf_old) = *((uint8_t*)&portbuf);
		sw_chatacnt = cKEY_CHATA_CNT;
	}
}


/**
 *********************************************************************************************
 * @brief		Initialize softconvert adc.
 *
 * @return		none
 *********************************************************************************************
 */
static void init_soft_adc(void)
{
	ADC_SetConstantTrg(cADUNIT_USR, cADREG_VR, TRG_ENABLE(cADCH_VR));
	ADC_Start(cADUNIT_USR, ADC_TRG_CONSTANT);						/* adc start */
}



/**
 *********************************************************************************************
 * @brief		Initialize check_id_error
 *
 * @return		none
 *********************************************************************************************
 */
void init_check_id_error(void)
{
#if defined(__CONTROL_MOTOR_CH1)
	shnterr1.S_Id_min_err = (q15_t)(cId_MinErr * FIX_15 / cA_MAX_CH1);
#endif /* __CONTROL_MOTOR_CH1 */
#if defined(__CONTROL_MOTOR_CH0)
	shnterr0.S_Id_min_err = (q15_t)(cId_MinErr * FIX_15 / cA_MAX_CH0);
#endif /* __CONTROL_MOTOR_CH0 */

}

/**
 *********************************************************************************************
 * @brief		check_id_error
 *
 * @param		vector_t* const motor
 *
 * @return		bool	TRUE:error / FALSE:
 *********************************************************************************************
 */
bool check_id_error(vector_t* const motor, shnterr_t* shnterr)
{
	bool	retval = false;

	if (motor->stage.itr == ciInitposition_i)
	{
		shnterr->S_Vd_rate = (abs(motor->drv.Vd.half[1]) * 100) / motor->drv.Vdc;
		if ((cVd_ONRate <= shnterr->S_Vd_rate) && (motor->drv.Id <= shnterr->S_Id_min_err))
		{
			if (++shnterr->S_error_counter >= cId_MinErrCnt)
			{
				retval = true;
			}
		}
		else
		{
			shnterr->S_error_counter = 0;
		}
	}
	else
	{
		shnterr->S_error_counter = 0;
	}
	return(retval);
}


/**
 *********************************************************************************************
 * @brief		user_setting
 *
 * @return		none
 *********************************************************************************************
 */
void user_setting(void)
{
	dac_t* const pdac = &dac;
	int32_t speed_temp = 0;
    int32_t target_speed;
	uint8_t ad_temp = 0;
    static uint8_t motor_direction = 0;
#ifdef  DEBUG_UART
    static uint8_t pre_ad_temp = 0;
    static uint8_t pre_adc_select = 0;
    
	static int32_t temp_speed_temp = 0;
    static int32_t temp_target_spd1 = 0;
#endif
	ADC_Result result;
#if defined(__CONTROL_MOTOR_CH1)
    
    char strtmp[] = "                                                   ";
    
	/* speed control */
	//result = ADC_GetConvertResult(cADUNIT_USR, cADREG_VR);
	//ad_temp = (uint8_t)(result.Bit.ADResult >> 4);
    target_speed = Get_Target_Speed();
    motor_direction = Get_Motor_Direction();
//    if(target_speed < 0){
//        target_speed = - target_speed;
//        motor_direction = 0;
//    } else {
//        motor_direction = 1;
//    }
    ad_temp = (uint8_t)(target_speed & 0xff);
    
	//result = ADC_GetConvertResult(cADUNIT_USR, cADREG_VR);
	//ad_temp = (uint8_t)(result.Bit.ADResult >> 4);
    
    // TODO: my code here
	//UART_SetTxData(UART0, ad_temp);
#ifdef  DEBUG_UART    
    if(Is_Uart_Ready_To_Send()){
        if((ad_temp <= pre_ad_temp - 2) || (ad_temp >= pre_ad_temp + 2)){
            pre_ad_temp = ad_temp;
            sprintf((char*) strtmp, "ADC = %d\r\n", (int)ad_temp);
            Send_Data_To_PC(strtmp);
        }
    }
#endif
//	printf("abc");
	// TODO: my code here
	
	if(ad_temp < cAD_MIN)
	{
		speed_temp = 0;
		motor_ready = 1;
	}
	else if(ad_temp < cAD_MAX)
	{
		speed_temp = (cSPEED_USER_MAX - cSPEED_USER_MIN) * (ad_temp - cAD_MIN) / (cAD_MAX - cAD_MIN) + cSPEED_USER_MIN;
	}
	else{
		speed_temp = cSPEED_USER_MAX;
	}

	if(motor_direction == 1)
	{
		target_spd1 = speed_temp;       /* CW */
	}
	else{
		target_spd1 = -speed_temp;      /* CCW */
	}

	if(motor_ready == 0)
	{
		target_spd1 = 0;
	}
#ifdef  DEBUG_UART
   if(Is_Uart_Ready_To_Send()){
        if(abs(target_spd1 - temp_target_spd1) > 2){
            temp_target_spd1 = target_spd1;
            sprintf((char*) strtmp, "target_spd1 = %d\r\n", (int)target_spd1);
            Send_Data_To_PC(strtmp);
        }
    }
#endif
	/* modul control */
	Motor_ch1.usr.com_user.modul = swdata.sw2;

	/* dac mode control */
	pdac->motch = 1;
	if((keydata != keydata_old) && (keydata_old == 0))
	{
		if(keydata == 0x01)
		{
			pdac->select = 0;
		}
		else if(keydata == 0x02)
		{
			pdac->select = 1;
		}
		else if(keydata == 0x04)
		{
			pdac->select = 2;
		}
		else if(keydata == 0x08)
		{
			pdac->select = 3;
		}
#ifdef  DEBUG_UART
        sprintf((char*) strtmp, "pdac = %d\r\n", (int)pdac->select);
        Send_Data_To_PC(strtmp);
#endif
	}
	keydata_old = keydata;

#endif
}

/**
 *********************************************************************************************
 * @brief		init_led
 *
 * @return		none
 *********************************************************************************************
 */
static void init_led(void)
{
	GPIO_WriteDataBit(GPIO_PA, GPIO_BIT_0, cLED_OFF);		/* LED1 */
	GPIO_SetOutputEnableReg(GPIO_PA, GPIO_BIT_0, ENABLE);

	GPIO_WriteDataBit(GPIO_PA, GPIO_BIT_1, cLED_OFF);		/* LED2 */
	GPIO_SetOutputEnableReg(GPIO_PA, GPIO_BIT_1, ENABLE);

	GPIO_WriteDataBit(GPIO_PA, GPIO_BIT_2, cLED_OFF);		/* LED3 */
	GPIO_SetOutputEnableReg(GPIO_PA, GPIO_BIT_2, ENABLE);

	GPIO_WriteDataBit(GPIO_PA, GPIO_BIT_3, cLED_OFF);		/* LED4 */
	GPIO_SetOutputEnableReg(GPIO_PA, GPIO_BIT_3, ENABLE);
}


/**
 *********************************************************************************************
 * @brief		led_display
 *
 * @return		none
 *********************************************************************************************
 */
static void led_display(void)
{
	dac_t* const pdac = &dac;

	/* flashing data */
	if(++flash_type1_cycle >= (cFLASH_TYPE1_CYCLE / cMAINLOOP_PRD))
	{
		flash_type1_cycle = 0;
		flash_type1 ^= 1;
	}
	if(++flash_type2_cycle >= (cFLASH_TYPE2_CYCLE / cMAINLOOP_PRD))
	{
		flash_type2_cycle = 0;
		flash_type2 ^= 1;
	}
	if(++flash_type3_cycle >= (cFLASH_TYPE3_CYCLE / cMAINLOOP_PRD))
	{
		flash_type3_cycle = 0;
		flash_type3 ^= 1;
	}

#if defined(__CONTROL_MOTOR_CH1)

	/* EMG display */
	if (Motor_ch1.drv.state.flg.emg_H == 1)
	{
		LED_EMG = cLED_ON;
	}
	else if(Motor_ch1.drv.state.flg.emg_S == 1)
	{
		LED_EMG = flash_type1;
	}
	else if(Motor_ch1.drv.state.flg.emg_I == 1)
	{
		LED_EMG = flash_type2;
	}
	else if(Motor_ch1.drv.state.flg.emg_DC == 1)
	{
		LED_EMG = flash_type3;
	}
	else
	{
		LED_EMG = cLED_OFF;
	}

	/* motor stage display */
	switch(Motor_ch1.stage.main)
	{
		case cStop:
			LED_STAGE = cLED_OFF;
			break;
		case cBootstrap:
			LED_STAGE = flash_type3;
			break;
		case cInitposition:
			LED_STAGE = flash_type3;
			break;
		case cForce:
			LED_STAGE = flash_type3;
			break;
		case cChange_up:
			LED_STAGE = flash_type3;
			break;
		case cSteady_A:
			LED_STAGE = cLED_ON;
			break;
		case cEmergency:
			LED_STAGE = cLED_OFF;
			break;
		default:
			LED_STAGE = cLED_OFF;
			break;
	}

	/* DAC mode display */
	if(pdac->motch == 1)
	{
		switch(pdac->select)
		{
			case 0:
				LED_DAC = cLED_OFF;
				break;
			case 1:
				LED_DAC = flash_type3;
				break;
			case 2:
				LED_DAC = flash_type2;
				break;
			case 3:
				LED_DAC = flash_type1;
				break;
			default:
				LED_DAC = cLED_OFF;
				break;
		}
	}
#endif
}

/**
 *********************************************************************************************
 * @brief		UiOutDataStart
 *
 * @param		uint8_t	_intch	call intve ch
 *
 * @return		none
 *********************************************************************************************
 */
void UiOutDataStart(uint8_t	_intch)
{
	dac_t* const pdac = &dac;

	if (_intch == pdac->motch)		/* Dac output ch = call intve ch? */
	{
		vector_t* pmotor=0;
		TSB_VE_TypeDef* pVE;
		uint16_t* const pdacout = DacData;

		if (pdac->motch == 0)
		{
			pVE = TSB_VE0;
#if defined(__CONTROL_MOTOR_CH0)
			pmotor = &Motor_ch0;
#endif
		}
		else
		{
			pVE = TSB_VE1;
#if defined(__CONTROL_MOTOR_CH1)
			pmotor = &Motor_ch1;
#endif
		}

		switch (pdac->select)
		{
			case 0:
				*(pdacout + 0) = (pVE->TMPREG0 >> (16 - pdac->datsft0)) ^ 0x8000;
				*(pdacout + 1) = (pVE->TMPREG1 >> (16 - pdac->datsft0)) ^ 0x8000;
				*(pdacout + 2) = (pVE->TMPREG2 >> (16 - pdac->datsft0)) ^ 0x8000;
				*(pdacout + 3) = pmotor->drv.theta.half[1];
				break;
			case 1:
				*(pdacout + 0) = (pmotor->drv.Id_ref << pdac->datsft0) ^ 0x8000;
				*(pdacout + 1) = (pmotor->drv.Id	 << pdac->datsft0) ^ 0x8000;
				*(pdacout + 2) = (pmotor->drv.Iq_ref << pdac->datsft0) ^ 0x8000;
				*(pdacout + 3) = (pmotor->drv.Iq	 << pdac->datsft0) ^ 0x8000;
				break;
			case 2:
				*(pdacout + 0) = (pmotor->drv.omega_com.half[1] << pdac->datsft0) ^ 0x8000;
				*(pdacout + 1) = (pmotor->drv.omega.half[1] 	<< pdac->datsft0) ^ 0x8000;
				*(pdacout + 2) = (pmotor->drv.omega_dev 		<< pdac->datsft1) ^ 0x8000;
				*(pdacout + 3) = (pmotor->drv.Iq_ref			<< pdac->datsft2) ^ 0x8000;
				break;
			case 3:
				*(pdacout + 0) = (pVE->TMPREG0              >> (16 - pdac->datsft0)) ^ 0x8000;
				*(pdacout + 1) = (pmotor->drv.Iq_ref        << pdac->datsft1)        ^ 0x8000;
				*(pdacout + 2) = (pmotor->drv.Id_ref        << pdac->datsft1)        ^ 0x8000;
				*(pdacout + 3) = (pmotor->drv.omega.half[1] << pdac->datsft2)        ^ 0x8000;
				break;
			default:
				*(pdacout + 0) = *(pdacout + 0) + 0x0100;
				*(pdacout + 1) = *(pdacout + 0);
				*(pdacout + 2) = *(pdacout + 0);
				*(pdacout + 3) = *(pdacout + 0);
				break;
		}

		DacWriteStart(DAC_SIO_CH);

	}
}


/******************************** END OF FILE *********************************/
