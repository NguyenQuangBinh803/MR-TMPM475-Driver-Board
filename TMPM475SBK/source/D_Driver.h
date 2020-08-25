/**
 ****************************************************************************
 * @file     D_Driver.h
 * @brief    Motor vector control driver Header File
 * @version  V1.0
 *****************************************************************************
 */
#ifndef _D_DRIVER_H
#define _D_DRIVER_H

#undef EXTERN
#ifdef DEFINE_APP
#define EXTERN
#else
#define EXTERN  extern
#endif


/*===================================================================*
      Proto Type Definition
 *===================================================================*/
EXTERN	void	H_Encoder(vector_t* const motor, TSB_EN_TypeDef* const ENx);
EXTERN	void	D_Detect_Rotor_Position(vector_t* const motor);
EXTERN	void	D_Control_Speed(vector_t* const motor);
EXTERN	void	D_SetZeroCurrent(vector_t* const _motor, uint8_t _ch);
EXTERN	bool	D_Check_OverCurrent(q15_t _ovc, q15_t _iu, q15_t _iv, q15_t _iw);

#undef	EXTERN
#endif /* _D_DRIVER_H */


/*************************** END OF FILE **************************************/
