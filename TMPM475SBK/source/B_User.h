/**
 ****************************************************************************
 * @file     B_User.h
 * @brief    Motor control for user Header File
 * @version  V1.0
 *****************************************************************************
 */
#ifndef _B_USER_H
#define _B_USER_H

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
EXTERN void B_Motor_Init(void);
EXTERN void	B_User_MotorControl(void);



#undef EXTERN
#endif /* _B_USER_H */

/*********************************** END OF FILE ******************************/
