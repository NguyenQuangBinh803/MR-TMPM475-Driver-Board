/**
 ****************************************************************************
 * @file     E_Sub.h
 * @brief    Sub Routine Functions
 * @version  V1.0
 *****************************************************************************
 */
#ifndef _E_SUB_H_INCLUDED
#define _E_SUB_H_INCLUDED

#undef EXTERN
#ifdef DEFINE_APP
#define EXTERN
#else
#define EXTERN  extern
#endif

/*===================================================================*
      Proto Type Definition
 *===================================================================*/
EXTERN	short	E_Sine(short theta);
EXTERN	short	E_Cosine(short theta);


#undef	EXTERN
#endif /* _E_SUB_H_INCLUDED */

/*********************************** END OF FILE ******************************/
