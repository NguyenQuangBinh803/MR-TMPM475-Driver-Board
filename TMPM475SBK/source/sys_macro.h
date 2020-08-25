/**
 ****************************************************************************
 * @file	 sys_macro.h
 * @brief	 System Macro Definitions
 * @version  V1.0
 *****************************************************************************
 */
#ifndef _SYS_MACRO_H_
#define _SYS_MACRO_H_


/*****************************************************************
 * Define The Macro
 *****************************************************************/

#define PAI 				(3.14159265)
#define PAI2				(2 * PAI)

#define SET 				(1)
#define CLEAR				(0)

#define HIGH				(1)
#define LOW 				(0)

#define ON					(1)
#define OFF 				(0)

#define true				(1==1)
#define false				(!true)

#define FIX_12				(0x1000L)						/* fix point Q12 4096 */
#define FIX_15				(0x8000L)						/* fix point Q15 32768 */
#define FIX_16				(0x10000L)						/* fix point Q16 65536 */
#define FIX_31				(0x80000000LL)					/* fix point Q31 */
#define cROUND_BIT15		(0x00008000)					/* Rounding off */

#define ELE_DEG(x)			(uint16_t)(FIX_16 * (x) / 360)	/* Electric Angle */

#define BIT8(a, b, c, d, e, f, g, h)									((a) * 0x80 + (b) * 0x40 + (c) * 0x20 + (d) * 0x10 + (e) * 0x08 + (f) * 0x04 + (g) * 0x02 + (h) * 0x01)

#define BIT16(a, b, c, d, e, f, g, h, aa, bb, cc, dd, ee, ff, gg, hh)	\
	((a) * 0x8000 + (b) * 0x4000 + (c) * 0x2000 + (d) * 0x1000 + (e) * 0x0800 + (f) * 0x0400 + (g) * 0x0200 + (h) \
	* 0x0100 + (aa) * 0x0080 + (bb) * 0x0040 + (cc) * 0x0020 + (dd) * 0x0010 + (ee) * 0x0008 + (ff) * 0x0004 + (gg) * 0x0002 + (hh) * 0x0001)

#define	BIT32(a,b,c,d,e,f,g,h,aa,bb,cc,dd,ee,ff,gg,hh,	\
			aaa,bbb,ccc,ddd,eee,fff,ggg,hhh,aaaa,bbbb,cccc,dddd,eeee,ffff,gggg,hhhh)  \
	( (uint32_t)(((0xFFFF & BIT16(a,b,c,d,e,f,g,h,aa,bb,cc,dd,ee,ff,gg,hh)) << 16)	\
	 | (0xFFFF & BIT16(aaa,bbb,ccc,ddd,eee,fff,ggg,hhh,aaaa,bbbb,cccc,dddd,eeee,ffff,gggg,hhhh))) )


#define RAM_BASE								(0x20000000UL)
#define BITBAND_OFFSET							(0x02000000UL)
#define BITBAND_SRAM_BASE						(RAM_BASE + BITBAND_OFFSET)
#define BITBAND_SRAM(addr, bitnum)				(BITBAND_SRAM_BASE + (((uint32_t)(addr) - RAM_BASE) << 5) + ((uint32_t)(bitnum) << 2))



/*****************************************************************
 * Define The Typedef
 *****************************************************************/
typedef int					bool;

typedef union
{
	q31_t word;
	q15_t half[2];
} q31_u;

typedef union
{
	uint32_t word;
	uint16_t half[2];
} uint32_u;

typedef struct
{
	uint8_t b0: 1;
	uint8_t b1: 1;
	uint8_t b2: 1;
	uint8_t b3: 1;
	uint8_t b4: 1;
	uint8_t b5: 1;
	uint8_t b6: 1;
	uint8_t b7: 1;
} byte_f;

typedef struct
{
	uint16_t b0: 1;
	uint16_t b1: 1;
	uint16_t b2: 1;
	uint16_t b3: 1;
	uint16_t b4: 1;
	uint16_t b5: 1;
	uint16_t b6: 1;
	uint16_t b7: 1;
	uint16_t b8: 1;
	uint16_t b9: 1;
	uint16_t b10: 1;
	uint16_t b11: 1;
	uint16_t b12: 1;
	uint16_t b13: 1;
	uint16_t b14: 1;
	uint16_t b15: 1;
} half_f;


typedef union
{
	uint8_t byte;
	byte_f bit;
} byte_u;

typedef union
{
	uint16_t half;
	uint8_t byte[2];
	half_f bit;
} half_u;


#endif /*_SYS_MACRO_H_ */


/*************************** END OF FILE **************************************/
