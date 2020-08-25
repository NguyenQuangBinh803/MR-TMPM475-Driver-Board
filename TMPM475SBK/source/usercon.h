/**
 ****************************************************************************
 * @file	 usercon.h
 * @brief	 User control
 * @version  V1.0
 *****************************************************************************
 */
#ifndef _USERCON_H
#define _USERCON_H


#undef EXTERN
#ifdef DEFINE_APP
#define EXTERN
#else
#define EXTERN  extern
#endif


/*===================================================================*
	Define Typedef
*===================================================================*/
typedef struct
{
	uint8_t	sw1	: 1;
	uint8_t	sw2	: 1;
	uint8_t	sw3	: 1;
	uint8_t	sw4	: 1;
	uint8_t	sw5	: 1;
	uint8_t	sw6	: 1;
	uint8_t	sw7	: 1;
	uint8_t	sw8	: 1;
} sw_t;


/* Error detection setting */
typedef struct
{
	uint16_t		S_error_counter;			/* Error counter */
	uint16_t		S_Vd_rate;					/* [%] Error detection d-axis voltage rate */
	q15_t			S_Id_min_err;				/* [A/maxA] Error detection d-axis minimum current */
} shnterr_t;


/*===================================================================*
      Proto Type Definition
 *===================================================================*/
EXTERN	void	init_user_control(void);
EXTERN	void	user_control(void);

EXTERN	void	init_check_id_error(void);
EXTERN	bool	check_id_error(vector_t* const motor, shnterr_t* shnterr);

EXTERN	void	UiOutDataStart(uint8_t	_intch);


/*===================================================================*
	Constant Data Definition
 *===================================================================*/
#define cVd_ONRate				(20)				/* [%] Percent of Vdc */
#define cId_MinErr				(0.05) 				/* [A] Error detection d-axis current */
#define cId_MinErrCnt			(5)					/*	   Error detection count */


/*===================================================================*
	Variable Definition
 *===================================================================*/


#if defined(__CONTROL_MOTOR_CH1)
EXTERN shnterr_t	shnterr1;						/*  */
#endif /* __CONTROL_MOTOR_CH1 */
#if defined(__CONTROL_MOTOR_CH0)
EXTERN shnterr_t	shnterr0;						/*  */
#endif /* __CONTROL_MOTOR_CH0 */



#undef EXTERN
#endif

/******************************** END OF FILE *********************************/
