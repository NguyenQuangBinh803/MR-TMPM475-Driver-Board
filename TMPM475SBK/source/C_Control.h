/**
 ****************************************************************************
 * @file     C_Control.h
 * @brief    Motor vector control Header File
 * @version  V1.0
 *****************************************************************************
 */
#ifndef _C_CONTROL_H_INCLUDED
#define _C_CONTROL_H_INCLUDED


#undef EXTERN
#ifdef DEFINE_APP
#define EXTERN
#else
#define EXTERN  extern
#endif


/*===================================================================*
      Constant Data Definition
 *===================================================================*/


/*===================================================================*
      Proto Type Definition
 *===================================================================*/
EXTERN	void	C_Control_Ref_Model(vector_t* const motor);
EXTERN	void	C_Common(vector_t* const motor);
EXTERN	void	C_Stage_Stop(vector_t* const motor);
EXTERN	void	C_Stage_Emergency(vector_t* const motor);
EXTERN	void	C_Stage_Bootstrap(vector_t* const motor);
EXTERN	void	C_Stage_Initposition(vector_t* const motor);
EXTERN	void	C_Stage_Force(vector_t* const motor);
EXTERN	void	C_Stage_Change_up(vector_t* const motor);
EXTERN	void	C_Stage_Steady_A(vector_t* const motor);
EXTERN	q31_t	C_command_limit_sub(q31_t now, q31_t target, q31_t lim_up, q31_t lim_down);


#undef	EXTERN
#endif /* _C_CONTROL_H_INCLUDED */

/*********************************** END OF FILE ******************************/
