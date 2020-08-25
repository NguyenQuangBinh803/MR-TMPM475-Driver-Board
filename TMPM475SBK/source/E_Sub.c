/**
 ****************************************************************************
 * @file	 E_Sub.c
 * @brief	 Sub Routine Functions
 * @version  V1.0
 *****************************************************************************
 */
#include "ipdefine.h"

#define DEFINE_APP
#include "E_Sub.h"
#undef DEFINE_APP


/**
 *********************************************************************************************
 * @brief		Cal Sine
 *				sin(x) = 3.140625x + 0.02026367x^2 -5.325196x^3 + 0.5446778x^4 + 1.800293x^5
 *
 * @param		short	theta	theta
 *
 * @return		short	sin(theta)
 *********************************************************************************************
 */
#define cSine1		(short)(FIX_12 *  3.140625)
#define cSine2		(short)(FIX_12 *  0.02026367)
#define cSine3		(short)(FIX_12 * -5.325196)
#define cSine4		(short)(FIX_12 *  0.5446778)
#define cSine5		(short)(FIX_12 *  1.800293)

short E_Sine(short theta)
{
	short x;
	short x1;
	long temp32;

	x = (short)(theta & 0x7fff);
	if (x >= ELE_DEG(90))
	{
		x = (q15_t)(ELE_DEG(180) - x);
	}
	x1 = x;
	temp32 = (cSine1 * (long)x1) << 1;
	x1 = (short)(x1 * (long)x >> (16 - 1));
	temp32 += (cSine2 * (long)x1) << 1;
	x1 = (short)(x1 * (long)x >> (16 - 1));
	temp32 += (cSine3 * (long)x1) << 1;
	x1 = (short)(x1 * (long)x >> (16 - 1));
	temp32 += (cSine4 * (long)x1) << 1;
	x1 = (short)(x1 * (long)x >> (16 - 1));
	temp32 += (cSine5 * (long)x1) << 1;
	temp32 <<= 3;

	if ((unsigned long)temp32 >= 0x7fffffff)
	{
		temp32 = 0x7fffffff;
	}
	if (theta <= 0)
	{
		temp32 *= ( -1);
	}

	return ((short)(temp32 >> 16));
}


/**
 *********************************************************************************************
 * @brief		E_Cosine
 *
 * @param		short	theta
 *
 * @return		short
 *********************************************************************************************
 */
short E_Cosine(short theta)
{
	return (E_Sine((short)(ELE_DEG(90) + theta)));
}

/*********************************** END OF FILE ******************************/
