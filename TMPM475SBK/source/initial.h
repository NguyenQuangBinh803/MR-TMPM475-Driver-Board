/**
 ****************************************************************************
 * @file	 initial.h
 * @brief	 Initialize Definitions
 * @version	 V1.0
 *****************************************************************************
 */
#ifndef _INITIAL_H
#define _INITIAL_H

#undef EXTERN
#ifdef DEFINE_APP
#define EXTERN
#else
#define EXTERN  extern
#endif


/*===================================================================*
      Proto Type Definition
 *===================================================================*/
EXTERN	void	init_Timer_interval4kH(void);
EXTERN	void	init_ENCen(void);
EXTERN	void	init_ADCen(void);
EXTERN	void	init_PMDen(void);
EXTERN	void	init_VEen(void);
EXTERN	void	init_PORT(void);
EXTERN	void	init_WDT(void);
EXTERN	void	init_UART(void);

#undef EXTERN
#endif /* _INITIAL_H */


/*************************** END OF FILE **************************************/
