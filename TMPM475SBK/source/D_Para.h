/**
 ****************************************************************************
 * @file	 D_Para.h
 * @brief	 Motor vector control Parameter Header File
 * @version  V1.0
 *****************************************************************************
 */
#ifndef _D_PARA_H
#define _D_PARA_H


/*===================================================================*
	  Control motor Channel
 *===================================================================*/
#define	__CONTROL_MOTOR_CH1								/* Control motor ch1 */
//#define	__CONTROL_MOTOR_CH0								/* Control motor ch0 */

/*===================================================================*
	  Select parts
 *===================================================================*/
#define	__USE_DAC										/* If define __USE_DAC, use dac ic control */

/*===================================================================*
	  Select special cotrol
 *===================================================================*/
//#define	__USE_CHECK_IERROR								/* If define detect current error control */

/*===================================================================*
	  Common Parameter Definition
 *===================================================================*/
/**** Main period ****/
#define	cMAINLOOP_PRD				(0.001)				/* [s] Cycle time of MAIN control */

/**** Filter Coefficient ****/
#define	cIXO_AVE					(5)					/* Zero current filter */
#define	cVDQ_AVE					(5)					/* Vdq,Vdc filter */
#define	cOMEGAENC_AVE				(3)					/* Omega from Encoder filter */

/*===================================================================*
	  By channel parameters
 *===================================================================*/
#if defined(__CONTROL_MOTOR_CH1)
#include "D_Para_ch1.h"
#endif /* __CONTROL_MOTOR_CH1 */

#if defined(__CONTROL_MOTOR_CH0)
#include "D_Para_ch0.h"
#endif /* __CONTROL_MOTOR_CH0 */


/*===================================================================*
	  parameters
 *===================================================================*/
#define	cMAINLOOP_CNT				((uint16_t)(cMAINLOOP_PRD / (250 * 1e-6)))


#endif /* _D_PARA_H */

/*************************** END OF FILE **************************************/

