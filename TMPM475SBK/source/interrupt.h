/**
 ****************************************************************************
 * @file	 interrupt.h
 * @brief	 Interrupt Functions
 * @version  V1.0
 *****************************************************************************
 */
#ifndef _INTERRUPT_H
#define _INTERRUPT_H

#undef EXTERN
#ifdef DEFINE_APP
#define EXTERN
#else
#define EXTERN  extern
#endif



/*===================================================================*
      Proto Type Definition
 *===================================================================*/
EXTERN	void	INT_interval_4kHz(void);
EXTERN	void	INTVCN1(void);
EXTERN	void	INTVCN0(void);

#undef EXTERN
#endif /*  _INTERRUPT_H */


/*************************** END OF FILE **************************************/
