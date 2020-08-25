/**
 ****************************************************************************
 * @file	 main.c
 * @brief	 main Functions
 * @version  V1.0
 *****************************************************************************
 */
#include <stdlib.h>

#define DEFINE_APP
#include "ipdefine.h"
#undef	DEFINE_APP
#include <stdio.h>
#include "tmpm475_wdt.h"
#include "tmpm475_uart.h"

#include "D_Para.h"
#include "D_Driver.h"
#include "C_Control.h"
#include "B_User.h"
#include "initial.h"
#include "usercon.h"
#include "dac_drv.h"

#include "nguyen_uart.h"
#include "nguyen_encoder.h"
#include "tmpm475_can_int.h"



/*===================================================================*
	Proto Type Definition
 *===================================================================*/
void main_loop(void);

/*===================================================================*
	Function
 *===================================================================*/

/**
 *********************************************************************************************
 * @brief		main Routine
 *
 * @return		int
 *********************************************************************************************
 */
int main(void)
{
#ifdef  DEBUG_UART
    char strtmp[] = "                                                   ";
#endif
	/***** Initial Setting *****/
	__disable_irq();									/* DI */

	//init_WDT();											/* Initial setting of WDT */

#if defined(__USE_ENCODER_CH1) || defined(__USE_ENCODER_CH0)
	init_ENCen();										/* Initial setting of INTENC */
#endif /* __USE_ENCODER */
    Encoder_Initializaion();
	init_ADCen();										/* Initial setting of ADC */
	init_PMDen();										/* Initial setting of PMD */
	init_VEen();										/* Initial setting of VE & start */
	//init_UART();
	Uart0_initialization();
	CAN_Initialization();
	
	
	B_Motor_Init();										/* Initial setting of the motor control */
	init_user_control();								/* Initial setting of user control */

#if defined(__USE_DAC)
	init_Dac();											/* Initial setting of Dac controller */
#endif /* __USE_DAC */

	init_Timer_interval4kH();							/* Initial setting of interval timer */

	__enable_irq(); 
	WDT_WriteClearCode();   
#ifdef  DEBUG_UART    
    sprintf((char*) strtmp, "Start programe %d\t", (int)1);
    Send_Data_To_PC(strtmp);
#endif
    //TestEncoder();
	/***** Main Loop *****/
	main_loop();

	return 0;
}

/**
 *********************************************************************************************
 * @brief		main_loop
 *
 * @return		none
 *********************************************************************************************
 */
void main_loop(void)
{
	
		
	
	while (1)
	{
        CAN_Data_Processing();
		if (M_Main_Counter >= cMAINLOOP_CNT)
		{
			vector_t* motor_ch;
            
			M_Main_Counter = 0;
            
			/***** Clear WDT *****/
            WDT_WriteClearCode();
            
            //Get_Velocity();
            
            
			/***** User control *****/
			user_control();
            
			/***** User motor control	*****/
			B_User_MotorControl();
            
			/***** Motor control  *****/
			/* Ch1 */
#if defined(__CONTROL_MOTOR_CH1)
			motor_ch = &Motor_ch1;
			D_SetZeroCurrent(motor_ch, cCH1);			/* Set Zero current */
			C_Control_Ref_Model(motor_ch);				/* Change of stage */
			C_Common(motor_ch); 						/* Stage Functions */
			C_Stage_Stop(motor_ch); 					/* Stop */
			C_Stage_Emergency(motor_ch);				/* Emargency */
			C_Stage_Bootstrap(motor_ch);				/* Positioning */
			C_Stage_Initposition(motor_ch); 			/* Bootstrap */
			C_Stage_Force(motor_ch);					/* Force commutation */
			C_Stage_Change_up(motor_ch);				/* Change up */
			C_Stage_Steady_A(motor_ch); 					/* Positioning */
            // TODO: my code here
			//UART_SetTxData(UART0, 100U);
			// TODO: my code here
#endif /* __CONTROL_MOTOR_CH1 */

#if defined(__CONTROL_MOTOR_CH0)
			/* Ch0 */
			motor_ch = &Motor_ch0;
			D_SetZeroCurrent(motor_ch, cCH0);			/* Set Zero current */
			C_Control_Ref_Model(motor_ch);				/* Change of stage */
			C_Common(motor_ch); 						/* Stage Functions */
			C_Stage_Stop(motor_ch); 					/* Stop */
			C_Stage_Emergency(motor_ch);				/* Emargency */
			C_Stage_Bootstrap(motor_ch);				/* Positioning */
			C_Stage_Initposition(motor_ch); 			/* Bootstrap */
			C_Stage_Force(motor_ch);					/* Force commutation */
			C_Stage_Change_up(motor_ch);				/* Change up */
			C_Stage_Steady_A(motor_ch); 				/* Normal RUN A (Speed control by currnt) */
#endif /* __CONTROL_MOTOR_CH0 */

		}
	}
}


/*********************************** END OF FILE ******************************/

