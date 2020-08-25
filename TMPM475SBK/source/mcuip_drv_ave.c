/**
 ****************************************************************************
 * @file	 mcuip_drv_ave.c
 * @brief	 MCU IP driver for A-VE
 * @version	 V1.0
 *****************************************************************************
 */
#include "ipdefine.h"

#include "tmpm475_adc.h"

#define DEFINE_APP
#include "mcuip_drv_ave.h"
#undef DEFINE_APP


/**
 *********************************************************************************************
 * @brief		Get EMGstatus
 *
 * @param		TSB_PMD_TypeDef *	PMDx	Select the PMD channel.
 *
 * @return		emg_status_e				EMG status
 *********************************************************************************************
 */
emg_status_e	PMD_GetEMG_Status(TSB_PMD_TypeDef* const PMDx)
{

	return ((emg_status_e)(*((__I uint32_t*)BITBAND_PERI(&PMDx->EMGSTA, B_EMGST))));

}

/**
 *********************************************************************************************
 * @brief		Release EMG protection.
 *
 * @param		TSB_PMD_TypeDef *	PMDx	Select the PMD channel.
 *
 * @return		none
 *********************************************************************************************
 */
void	PMD_ReleaseEMG_Protection(TSB_PMD_TypeDef* const PMDx)
{
	emg_status_e	emgst;

	emgst = PMD_GetEMG_Status(PMDx);

	if (emgst == cEMGProtected)
	{
		if ((*((__I uint32_t*)BITBAND_PERI(&PMDx->EMGSTA, B_EMGI))) == 1)
		{
			if (PMDx == TSB_PMD1)
			{
				TSB_VE1->EMGRS = 1;						/*Release EMG protection */
			}
			else
			{
				TSB_VE0->EMGRS = 1;						/*Release EMG protection */
			}
		}
	}

}

/**
 *********************************************************************************************
 * @brief		VE start
 *
 * @param		TSB_VE_TypeDef* const	VEx		Set the VE address.
 * @param		uint8_t					_ch		Select the VE channel.
 *
 * @return		none
 *********************************************************************************************
 */
void	VE_Start(TSB_VE_TypeDef* const VEx, uint8_t _ch)
{

	VEx->CPURUNTRG = VE_START;

}

/**
 *********************************************************************************************
 * @brief		Get Phase Current from VE register.
 *
 * @param		TSB_VE_TypeDef* const	VEx		Set the VE address.
 * @param		uint8_t					_ch		Select the VE channel.
 * @param		q15_t*					_ia		U-phase current value store address.
 * @param		q15_t*					_ib		V-phase current value store address.
 * @param		q15_t*					_ic		W-phase current value store address.
 *
 * @return		none
 *********************************************************************************************
 */
void	VE_GetPhaseCurrent(TSB_VE_TypeDef* const VEx, uint8_t _ch, q15_t* _ia, q15_t* _ib, q15_t* _ic)
{
	q15_t	ia, ib, ic;
	q15_t	izero;

	izero = VEx->IAO;
	ia = izero - VEx->IAADC;
	izero = VEx->IBO;
	ib = izero - VEx->IBADC;
	izero = VEx->ICO;
	ic = izero - VEx->ICADC;

	*_ia = ia;
	*_ib = ib;
	*_ic = ic;
}

/**
 *********************************************************************************************
 * @brief		Get current adc data from VE register.
 *
 * @param		TSB_VE_TypeDef* const	VEx		Set the VE address.
 * @param		uint8_t					_ch		Select the VE channel.
 * @param		uint32_t*				_adc_ia	U-phase current ad value store address.
 * @param		uint32_t*				_adc_ib	V-phase current ad value store address.
 * @param		uint32_t*				_adc_ic	W-phase current ad value store address.
 *
 * @return		none
 *********************************************************************************************
 */
void	VE_GetCurrentAdcData(TSB_VE_TypeDef* const VEx, uint8_t _ch, uint32_t* _adc_ia, uint32_t* _adc_ib, uint32_t* _adc_ic)
{

	*_adc_ia = VEx->IAADC;
	*_adc_ib = VEx->IBADC;
	*_adc_ic = VEx->ICADC;

}

/**
 *********************************************************************************************
 * @brief		Get data from VE registers.
 *
 * @param		TSB_VE_TypeDef* const	VEx		Set the VE address.
 * @param		uint8_t					_ch		Select the VE channel.
 * @param		vector_t* const			_motor	Structure address of vector control variable.
 *
 * @return		none
 *********************************************************************************************
 */
void	VE_GetdataFromVEreg(TSB_VE_TypeDef* const VEx, uint8_t _ch, vector_t* const _motor)
{
	_motor->drv.Vdc = VEx->VDC;									/* Read Vdc */
	_motor->drv.Vd.word = VEx->VD;								/* Read Vd */
	_motor->drv.Vq.word = VEx->VQ;								/* Read Vd */
	_motor->drv.Id = (q15_t)(VEx->ID >> 16);					/* Read Id */
	_motor->drv.Iq = (q15_t)(VEx->IQ >> 16);					/* Read Iq */
}

/**
 *********************************************************************************************
 * @brief		Set data to VE registers in Stop stage.
 *
 * @param		TSB_VE_TypeDef* const	VEx		Set the VE address.
 * @param		uint8_t					_ch		Select the VE channel.
 * @param		vector_t* const			_motor	Structure address of vector control variable.
 *
 * @return		none
 *********************************************************************************************
 */
void	VE_SetdataToVEreg_Stop(TSB_VE_TypeDef* const VEx, uint8_t _ch, const vector_t* const _motor)
{

	VEx->TASKAPP = SET_TAPP(TAPP_OUT_CON);						/* VE start from output control */
	VEx->ACTSCH = SET_ACTSCH(SCH_9);							/* Schedule 9 */

	VEx->MODE = VEMODE_STOP;									/* Output OFF */

	VEx->ID = 0;
	VEx->IQ = 0;
	VEx->VD = 0;
	VEx->VQ = 0;
	VEx->VDIH = 0;												/* Clear Current PI Control Integral Term Registers */
	VEx->VDILH = 0;
	VEx->VQIH = 0;
	VEx->VQILH = 0;
	VEx->IDREF = 0;
	VEx->IQREF = 0;
	VEx->THETA = 0;
	VEx->OMEGA = 0;
	VEx->SECTOR = 0;
	VEx->SECTORM = 0;
	VEx->MINPLS = 0;

}

/**
 *********************************************************************************************
 * @brief		Set data to VE registers in Bootstrap stage.
 *
 * @param		TSB_VE_TypeDef* const	VEx		Set the VE address.
 * @param		uint8_t					_ch		Select the VE channel.
 * @param		vector_t* const			_motor	Structure address of vector control variable.
 *
 * @return		none
 *********************************************************************************************
 */
void	VE_SetdataToVEreg_Bootstrap(TSB_VE_TypeDef* const VEx, uint8_t _ch, const vector_t* const _motor)
{

	VEx->TASKAPP = SET_TAPP(TAPP_SINCOS);						/* VE start from SIN/COS */
	VEx->ACTSCH = SET_ACTSCH(SCH_4);							/* Schedule 4 */

	VEx->MODE = VEMODE_BOOT;									/* Output ON */

}

/**
 *********************************************************************************************
 * @brief		Set data to VE registers in Initposition stage for current control.
 *
 * @param		TSB_VE_TypeDef* const	VEx		Set the VE address.
 * @param		uint8_t					_ch		Select the VE channel.
 * @param		vector_t* const			_motor	Structure address of vector control variable.
 *
 * @return		none
 *********************************************************************************************
 */
void	VE_SetdataToVEreg_Initposition_i(TSB_VE_TypeDef* const VEx, uint8_t _ch, const vector_t* const _motor)
{

	VEx->TASKAPP = SET_TAPP(TAPP_CRT_CON);					/* VE start from current control */
	VEx->ACTSCH = SET_ACTSCH(SCH_1);						/* Schedule 1 */

	VEx->MODE = VEMODE_INITPOS;								/* Output ON */

	VEx->IDREF = _motor->drv.Id_ref;						/* Set Id */
	VEx->IQREF = _motor->drv.Iq_ref; 						/* Set Iq */
	VEx->THETA = _motor->drv.theta.half[1];
	VEx->OMEGA = _motor->drv.omega.half[1];
	VEx->MINPLS = 0;

}

/**
 *********************************************************************************************
 * @brief		Set data to VE registers in Initposition stage for voltage control.
 *
 * @param		TSB_VE_TypeDef* const	VEx		Set the VE address.
 * @param		uint8_t					_ch		Select the VE channel.
 * @param		vector_t* const			_motor	Structure address of vector control variable.
 *
 * @return		none
 *********************************************************************************************
 */
void	VE_SetdataToVEreg_Initposition_v(TSB_VE_TypeDef* const VEx, uint8_t _ch, const vector_t* const _motor)
{
	VEx->TASKAPP = SET_TAPP(TAPP_SINCOS);						/* VE start from SIN/COS */
	VEx->ACTSCH = SET_ACTSCH(SCH_4);							/* Schedule 4 */

	VEx->MODE = VEMODE_INITPOS;									/* Output ON */

	VEx->VD = _motor->drv.Vd_out;								/* Vd */
	VEx->VQ = 0;
	VEx->THETA = _motor->drv.theta.half[1];
	VEx->OMEGA = _motor->drv.omega.half[1];
	VEx->MINPLS = 0;

}

/**
 *********************************************************************************************
 * @brief		Set data to VE registers in Force stage for current control.
 *
 * @param		TSB_VE_TypeDef* const	VEx		Set the VE address.
 * @param		uint8_t					_ch		Select the VE channel.
 * @param		vector_t* const			_motor	Structure address of vector control variable.
 *
 * @return		none
 *********************************************************************************************
 */
void	VE_SetdataToVEreg_Force_i(TSB_VE_TypeDef* const VEx, uint8_t _ch, const vector_t* const _motor)
{
	VEx->TASKAPP = SET_TAPP(TAPP_CRT_CON);						/* VE start from current control */
	VEx->ACTSCH = SET_ACTSCH(SCH_1);							/* Schedule 1 */

	VEx->MODE = VEMODE_FORCE;									/* Output ON */

	VEx->IDREF = _motor->drv.Id_ref;						/* Set Id */
	VEx->IQREF = _motor->drv.Iq_ref; 						/* Set Iq */
	VEx->THETA = _motor->drv.theta.half[1];
	VEx->OMEGA = _motor->drv.omega.half[1];
	VEx->MINPLS = 0;

}

/**
 *********************************************************************************************
 * @brief		Set data to VE registers in Force stage for voltage control.
 *
 * @param		TSB_VE_TypeDef* const	VEx		Set the VE address.
 * @param		uint8_t					_ch		Select the VE channel.
 * @param		vector_t* const			_motor	Structure address of vector control variable.
 *
 * @return		none
 *********************************************************************************************
 */
void	VE_SetdataToVEreg_Force_v(TSB_VE_TypeDef* const VEx, uint8_t _ch, const vector_t* const _motor)
{
	VEx->TASKAPP = SET_TAPP(TAPP_SINCOS);						/* VE start from SIN/COS */
	VEx->ACTSCH = SET_ACTSCH(SCH_4);							/* Schedule 4 */

	VEx->MODE = VEMODE_FORCE;									/* Output ON */

	VEx->VD = _motor->drv.Vd_out;								/* Vd */
	VEx->VQ = 0; 												/* Vq = 0 */
	VEx->THETA = _motor->drv.theta.half[1];						/* Theta set */
	VEx->OMEGA = _motor->drv.omega.half[1];						/* Omega set */
	VEx->MINPLS = 0;

}

/**
 *********************************************************************************************
 * @brief		Set data to VE registers in Change_up stage.
 *
 * @param		TSB_VE_TypeDef* const	VEx		Set the VE address.
 * @param		uint8_t					_ch		Select the VE channel.
 * @param		vector_t* const			_motor	Structure address of vector control variable.
 *
 * @return		none
 *********************************************************************************************
 */
void	VE_SetdataToVEreg_Change_up(TSB_VE_TypeDef* const VEx, uint8_t _ch, const vector_t* const _motor)
{
	VEx->TASKAPP = SET_TAPP(TAPP_CRT_CON);						/* VE start from current control */
	VEx->ACTSCH = SET_ACTSCH(SCH_1);							/* Schedule 1 */

	VEx->MODE = VEMODE_CHGUP;									/* Output ON */

	VEx->IDREF = _motor->drv.Id_ref;						/* Set Id */
	VEx->IQREF = _motor->drv.Iq_ref; 						/* Set Iq */
	VEx->THETA = _motor->drv.theta.half[1];
	VEx->OMEGA = _motor->drv.omega.half[1];
	VEx->MINPLS = 0;

}

/**
 *********************************************************************************************
 * @brief		Set data to VE registers in Steady_A stage.
 *
 * @param		TSB_VE_TypeDef* const	VEx		Set the VE address.
 * @param		uint8_t					_ch		Select the VE channel.
 * @param		vector_t* const			_motor	Structure address of vector control variable.
 *
 * @return		none
 *********************************************************************************************
 */
void	VE_SetdataToVEreg_Steady_A(TSB_VE_TypeDef* const VEx, uint8_t _ch, const vector_t* const _motor)
{
	VEx->TASKAPP = SET_TAPP(TAPP_CRT_CON);						/* VE start from current control */
	VEx->ACTSCH = SET_ACTSCH(SCH_1);							/* Schedule 1 */

	VEx->MODE = VEMODE_STEADY;									/* Output ON */

	VEx->IDREF = _motor->drv.Id_ref;							/* Id set */
	VEx->IQREF = _motor->drv.Iq_ref;							/* Iq set */
	VEx->THETA = _motor->drv.theta.half[1];						/* Theta set */
	VEx->OMEGA = _motor->drv.omega.half[1];						/* Omega set */
	VEx->MINPLS = 0;

}

/**
 *********************************************************************************************
 * @brief		Set data to VE registers in Emergency stage.
 *
 * @param		TSB_VE_TypeDef* const	VEx		Set the VE address.
 * @param		uint8_t					_ch		Select the VE channel.
 * @param		vector_t* const			_motor	Structure address of vector control variable.
 *
 * @return		none
 *********************************************************************************************
 */
void	VE_SetdataToVEreg_Emergency(TSB_VE_TypeDef* const VEx, uint8_t _ch, const vector_t* const _motor)
{
	VEx->TASKAPP = SET_TAPP(TAPP_OUT_CON);					/* VE start from output control */
	VEx->ACTSCH = SET_ACTSCH(SCH_9);						/* Schedule 9 */

	VEx->MODE = VEMODE_EMG;									/* Output OFF */

}

/**
 *********************************************************************************************
 * @brief		Set zero current data to VE register.
 *
 * @param		TSB_VE_TypeDef* const	VEx		Set the VE address.
 * @param		uint8_t					_ch		Select the VE channel.
 * @param		uint32_t				_z_ia	U Phase value.
 * @param		uint32_t				_z_ib	V Phase value.
 * @param		uint32_t				_z_ic	W Phase value.
 *
 * @return		none
 *********************************************************************************************
 */
void	VE_SetZeroCurrentData(TSB_VE_TypeDef* const VEx, uint8_t _ch, uint32_t _z_ia, uint32_t _z_ib, uint32_t _z_ic)
{
	VEx->IAO = _z_ia;
	VEx->IBO = _z_ib;
	VEx->ICO = _z_ic;

}

/**
 *********************************************************************************************
 * @brief		Set VEVDC reg.
 *
 * @param		TSB_VE_TypeDef* const	VEx		Set the VE address.
 * @param		uint8_t					_ch		Select the VE channel.
 * @param		q15_t					_dat	Power supply voltage(Q15)
 *
 * @return		none
 *********************************************************************************************
 */
void	VE_SetVDCreg(TSB_VE_TypeDef* const VEx, uint8_t _ch, q15_t _dat)
{
	VEx->VDC = _dat;
}

/**
 *********************************************************************************************
 * @brief		Set modulation type.
 *
 * @param		TSB_VE_TypeDef* const	VEx		Set the VE address.
 * @param		uint8_t					_ch		Select the VE channel.
 * @param		uint8_t					_dat	modulation type.
 *
 * @return		none
 *********************************************************************************************
 */
void	VE_SetModulType(TSB_VE_TypeDef* const VEx, uint8_t _ch, uint8_t _dat)
{
	(*((__IO uint32_t*)BITBAND_PERI(&VEx->FMODE, B_C2PEN))) = _dat;
}

/**
 *********************************************************************************************
 * @brief		PMD IP Initialize
 *
 * @param		TSB_PMD_TypeDef* const	PMDx		Select the PMD channel.
 * @param		PMD_InitTypeDef* const	_initdata	The structure containing basic PMD configuration.
 *
 * @return		none
 *********************************************************************************************
 */
void IP_PMD_init(TSB_PMD_TypeDef* const PMDx, PMD_InitTypeDef* const _initdata)
{

	PMDx->MODESEL = WBUF_BUS;

	/***** active setting *****/
	PMDx->MDPOT = cMDPOT_INI;
	if (_initdata->poll == 1)
	{
		PMDx->MDPOT |= (1U << B_POLL);
	}
	else
	{
		PMDx->MDPOT &= ~(1U << B_POLL);
	}
	if (_initdata->polh == 1)
	{
		PMDx->MDPOT |= (1U << B_POLH);
	}
	else
	{
		PMDx->MDPOT &= ~(1U << B_POLH);
	}

	PMDx->MDOUT = cMDOUT_OFF;							/* Output off */
	PMDx->CMPU = 0;
	PMDx->CMPV = 0;
	PMDx->CMPW = 0;

	/***** EMG setting *****/
#if (1)

	PMDx->EMGCR = cEMG_ENA; 							/* EMG Enable */
	PMDx->EMGCR = cEMG_Release; 						/* EMG Release */
#else

	PMDx->EMGREL = 0x5A;								/* Disable code */
	PMDx->EMGREL = 0xA5;
	PMDx->EMGCR = cEMG_DIS; 							/* EMG Disable */
#endif

	/* OVV disable set */
	PMDx->EMGREL = 0x5A;								/* Disable code */
	PMDx->EMGREL = 0xA5;
	PMDx->OVVCR = cOVV_DIS;


	PMDx->PORTMD = cPORTMD_INI;							/* Tool break */
	PMDx->MDCR = cMDCR_INI;

	PMDx->MDPRD = _initdata->pwmfreq;					/* PWM frequency */
	PMDx->DTR = _initdata->deadtime; 					/* Dead timewr set */
	PMDx->MDEN = 0x01;									/* PMD enable (Set after set MDOUT,MDPOT) */

	/***** port setting *****/
	if (PMDx == TSB_PMD1)
	{
		TSB_PG->FR1 |= BIT8(0, 0, 1, 1, 1, 1, 1, 1); 			/* PMD1 PORT output Enable */
		TSB_PG->CR  |= BIT8(0, 0, 1, 1, 1, 1, 1, 1); 			/* PMD1 PORT output Enable */

		if ((*((__IO uint32_t*)BITBAND_PERI(&PMDx->EMGCR, B_EMGEN))) == 1)	/* EMG enable? */
		{
			TSB_PG->FR1 |= BIT8(0, 1, 0, 0, 0, 0, 0, 0);		/* PMD1 PORT Enable */
			TSB_PG->IE  |= BIT8(0, 1, 0, 0, 0, 0, 0, 0); 		/* PMD1 PORT Enable */
		}

		if ((*((__IO uint32_t*)BITBAND_PERI(&PMDx->OVVCR, B_OVVEN))) == 1)	/* OVV enable? */
		{
			TSB_PG->FR1 |= BIT8(1, 0, 0, 0, 0, 0, 0, 0); 		/* PMD1 PORT Enable */
			TSB_PG->IE  |= BIT8(1, 0, 0, 0, 0, 0, 0, 0); 		/* PMD1 PORT Enable */
		}
	}
	else if (PMDx == TSB_PMD0)
	{
		TSB_PC->FR1 |= BIT8(0, 0, 1, 1, 1, 1, 1, 1); 			/* PMD0 PORT output Enable */
		TSB_PC->CR  |= BIT8(0, 0, 1, 1, 1, 1, 1, 1); 			/* PMD0 PORT output Enable */

		if ((*((__IO uint32_t*)BITBAND_PERI(&PMDx->EMGCR, B_EMGEN))) == 1)	/* EMG enable? */
		{
			TSB_PC->FR1 |= BIT8(0, 1, 0, 0, 0, 0, 0, 0); 		/* PMD0 PORT Enable */
			TSB_PC->IE  |= BIT8(0, 1, 0, 0, 0, 0, 0, 0); 		/* PMD0 PORT Enable */
		}

		if ((*((__IO uint32_t*)BITBAND_PERI(&PMDx->OVVCR, B_OVVEN))) == 1)	/* OVV enable? */
		{
			TSB_PC->FR1 |= BIT8(1, 0, 0, 0, 0, 0, 0, 0); 		/* PMD0 PORT Enable */
			TSB_PC->IE  |= BIT8(1, 0, 0, 0, 0, 0, 0, 0); 		/* PMD0 PORT Enable */
		}
	}

	/***** Release EMG protection *****/
	if ((*((__I uint32_t*)BITBAND_PERI(&PMDx->EMGSTA, B_EMGI))) == 1)
	{
		(*((__O uint32_t*)BITBAND_PERI(&PMDx->EMGCR, B_EMGRS))) = 1;
	}


	/***** Triger setting *****/
	PMDx->TRGCMP0 = 0; 									/* TRG position clear */
	PMDx->TRGCMP1 = 0;
	PMDx->TRGCMP2 = 0;
	PMDx->TRGCMP3 = 0;

	PMDx->TRGCR = cTRG_SETTING;
	PMDx->TRGMD = cTRGMD_SETTING;

	PMDx->TRGSEL = 0;									/* TRG No = Sector = 0 */

	PMDx->TRGSYNCR = cTRGSYNCR_INI;

	PMDx->MODESEL = WBUF_VE;							/* W-Buff from VE */

}

/**
 *********************************************************************************************
 * @brief		IP_VE_init
 *
 * @param		TSB_VE_TypeDef* const	VEx			Select the VE channel.
 * @param		VE_InitTypeDef* const	_initdata	The structure containing basic VE configuration
 *
 * @return		none
 *********************************************************************************************
 */
void IP_VE_init(TSB_VE_TypeDef* const VEx, VE_InitTypeDef* const _initdata)
{

	/*********************** VE Control Register ********************************/
	VEx->EN = 0x01; 									/* VE Enable */

	VEx->TASKAPP = SET_TAPP(TAPP_OUT_CON);				/* VE start from output control */
	VEx->ACTSCH = SET_ACTSCH(SCH_9); 					/* Schedule 9 */

	VEx->REPTIME = SET_REPTIME(_initdata->reptime);
	VEx->TRGMODE = SET_TRGMODE(_initdata->trgmode);

	VEx->ERRINTEN = SET_ERRINTEN(cVERREN_INI);

	VEx->TMPREG0 = 0;									/* Temporary register clear */
	VEx->TMPREG1 = 0;
	VEx->TMPREG2 = 0;
	VEx->TMPREG3 = 0;
	VEx->TMPREG4 = 0;
	VEx->TMPREG5 = 0;

	/*********************** VE Register for Channel 1 **************************/
	VEx->MODE = VEMODE_STOP;

	VEx->FMODE = cFMODE_INI;
	VEx->TPWM = _initdata->tpwm;

	VEx->OMEGA = 0;
	VEx->THETA = 0;

	VEx->COS = 0;
	VEx->SIN = 0;
	VEx->COSM = 0;
	VEx->SINM = 0;

	VEx->IDREF = 0;
	VEx->IQREF = 0;

	VEx->VD = 0;
	VEx->VQ = 0;

	VEx->CIDKI = _initdata->idki;
	VEx->CIDKP = _initdata->idkp;
	VEx->CIQKI = _initdata->iqki;
	VEx->CIQKP = _initdata->iqkp;

	VEx->VDIH = 0;
	VEx->VDILH = 0;
	VEx->VQIH = 0;
	VEx->VQILH = 0;

	VEx->MCTLF = 0x00;

	VEx->FPWMCHG = 0x7fff;								/* Hard control off */

	VEx->MDPRD = _initdata->pwmfreq;		 			/* PWM frequency */

	VEx->MINPLS = 0;

	VEx->SECTOR = 0;
	VEx->SECTORM = 0;

	VEx->IAO = _initdata->zerooffset;
	VEx->IBO = _initdata->zerooffset;
	VEx->ICO = _initdata->zerooffset;

	VEx->IAADC = 0;
	VEx->IBADC = 0;
	VEx->ICADC = 0;

	VEx->VDC = 0;
	VEx->ID = 0;
	VEx->IQ = 0;

	VEx->CMPU = 0;
	VEx->CMPV = 0;
	VEx->CMPW = 0;

	VEx->OUTCR = 0x0000;								/* Output UP/DOWN = OFF/OFF */

	VEx->TRGCRC = 0;

	VEx->TRGCMP0 = 0;
	VEx->TRGCMP1 = 0;

	VEx->TRGSEL = 0;

	VEx->EMGRS = 0;

	VEx->CPURUNTRG = VE_START;

}


/**
 *********************************************************************************************
 * @brief		ADC Inisial set
 *
 * @param		TSB_AD_TypeDef* const	ADx			Select the ADC channel.
 * @param		AD_InitTypeDef* const	_initdata	The structure containing basic ADC configuration
 *
 * @return		none
 *********************************************************************************************
 */
void IP_ADC_init(TSB_AD_TypeDef* const ADx, AD_InitTypeDef* const _initdata)
{
	uint32_t data32;

	/***** PMD TRG Start mode set *****/

	/* ADx Program set */
	if (_initdata->pmd_ch == cPMD0)
	{
		ADx->PSEL0  = TRG_ENABLE(PMD_PROG0);		/* PMD0 TRG0:BProg0 at Sector0 */
		ADx->PSEL1  = TRG_ENABLE(PMD_PROG1);		/* PMD0 TRG1:BProg1 at Sector1 */
		ADx->PSEL2  = TRG_ENABLE(PMD_PROG2);		/* PMD0 TRG2:BProg2 at Sector2 */
		ADx->PSEL3  = TRG_ENABLE(PMD_PROG3);		/* PMD0 TRG3:BProg3 at Sector3 */
		ADx->PSEL4  = TRG_ENABLE(PMD_PROG4);		/* PMD0 TRG4:BProg4 at Sector4 */
		ADx->PSEL5  = TRG_ENABLE(PMD_PROG5);		/* PMD0 TRG5:BProg5 at Sector5 */
	}
	else if (_initdata->pmd_ch == cPMD1)
	{
		ADx->PSEL6  = TRG_ENABLE(PMD_PROG0);		/* PMD1 TRG0:BProg0 at Sector0 */
		ADx->PSEL7  = TRG_ENABLE(PMD_PROG1);		/* PMD1 TRG1:BProg1 at Sector1 */
		ADx->PSEL8  = TRG_ENABLE(PMD_PROG2);		/* PMD1 TRG2:BProg2 at Sector2 */
		ADx->PSEL9  = TRG_ENABLE(PMD_PROG3);		/* PMD1 TRG3:BProg3 at Sector3 */
		ADx->PSEL10 = TRG_ENABLE(PMD_PROG4);		/* PMD1 TRG4:BProg4 at Sector4 */
		ADx->PSEL11 = TRG_ENABLE(PMD_PROG5);		/* PMD1 TRG5:BProg5 at Sector5 */
	}

	if (_initdata->pints == cPINTS_A)
	{
		ADx->PINTS0 = PMD_INTADPDA;					/* End of all prog generate INTADA */
		ADx->PINTS1 = PMD_INTADPDA;
		ADx->PINTS2 = PMD_INTADPDA;
		ADx->PINTS3 = PMD_INTADPDA;
		ADx->PINTS4 = PMD_INTADPDA;
		ADx->PINTS5 = PMD_INTADPDA;
	}
	else
	{
		ADx->PINTS0 = PMD_INTADPDB;					/* End of all prog generate INTADB */
		ADx->PINTS1 = PMD_INTADPDB;
		ADx->PINTS2 = PMD_INTADPDB;
		ADx->PINTS3 = PMD_INTADPDB;
		ADx->PINTS4 = PMD_INTADPDB;
		ADx->PINTS5 = PMD_INTADPDB;
	}

	if (ADx == TSB_ADB)
	{
		/* AD unitB */
		/* ADx->PSET5,PSET0	REG0:W, REG1:V, REG2:U, REG3:Vdc */
		data32 = (((0x80 | (VE_PHASE_W    << 5U) | _initdata->iwch)) \
		         |((0x80 | (VE_PHASE_V    << 5U) | _initdata->ivch)  << 8U) \
		         |((0x80 | (VE_PHASE_U    << 5U) | _initdata->iuch)  << 16U) \
		         |((0x80 | (VE_PHASE_NONE << 5U) | _initdata->vdcch) << 24U));
		ADx->PSET5 = data32;
		ADx->PSET0 = data32;

		/* ADx->PSET1,PSET2	REG0:U, REG1:W, REG2:V, REG3:Vdc */
		data32 = (((0x80 | (VE_PHASE_U    << 5U) | _initdata->iuch)) \
		        | ((0x80 | (VE_PHASE_W    << 5U) | _initdata->iwch)  << 8U) \
		        | ((0x80 | (VE_PHASE_V    << 5U) | _initdata->ivch)  << 16U) \
		        | ((0x80 | (VE_PHASE_NONE << 5U) | _initdata->vdcch) << 24U));
		ADx->PSET1 = data32;
		ADx->PSET2 = data32;

		/* ADx->PSET3,PSET4	REG0:V, REG1:U, REG2:W, REG3:Vdc */
		data32 = (((0x80 | (VE_PHASE_V    << 5U) | _initdata->ivch)) \
		        | ((0x80 | (VE_PHASE_U    << 5U) | _initdata->iuch)  << 8U) \
		        | ((0x80 | (VE_PHASE_W    << 5U) | _initdata->iwch)  << 16U) \
		        | ((0x80 | (VE_PHASE_NONE << 5U) | _initdata->vdcch) << 24U));
		ADx->PSET3	= data32;
		ADx->PSET4	= data32;

	}
	else
	{
		/* AD unitA */
		/* ADx->PSET5,PSET0	REG0:V, REG1:W, REG2:U, REG3:Vdc */
		data32 = (((0x80 | (VE_PHASE_V    << 5U) | _initdata->ivch)) \
		        | ((0x80 | (VE_PHASE_W    << 5U) | _initdata->iwch)  << 8U) \
		        | ((0x80 | (VE_PHASE_U    << 5U) | _initdata->iuch)  << 16U) \
		        | ((0x80 | (VE_PHASE_NONE << 5U) | _initdata->vdcch) << 24U));
		ADx->PSET5 = data32;
		ADx->PSET0 = data32;

		/* ADx->PSET1,PSET2	REG0:W, REG1:U, REG2:V, REG3:Vdc */
		data32 = (((0x80 | (VE_PHASE_W    << 5U) | _initdata->iwch)) \
		        | ((0x80 | (VE_PHASE_U    << 5U) | _initdata->iuch)  << 8U) \
		        | ((0x80 | (VE_PHASE_V    << 5U) | _initdata->ivch)  << 16U) \
		        | ((0x80 | (VE_PHASE_NONE << 5U) | _initdata->vdcch) << 24U));
		ADx->PSET1 = data32;
		ADx->PSET2 = data32;

		/* ADx->PSET3,PSET4	REG0:U, REG1:V, REG2:W, REG3:Vdc */
		data32 = (((0x80 | (VE_PHASE_U    << 5U) | _initdata->iuch)) \
		        | ((0x80 | (VE_PHASE_V    << 5U) | _initdata->ivch)  << 8U) \
		        | ((0x80 | (VE_PHASE_W    << 5U) | _initdata->iwch)  << 16U) \
		        | ((0x80 | (VE_PHASE_NONE << 5U) | _initdata->vdcch) << 24U));
		ADx->PSET3	= data32;
		ADx->PSET4	= data32;
	}


	/* Set ADC Clock */
	ADC_SetClk(ADx, ADC_CONVERSION_CLK_1, ADC_PHASED_CLK_34, ADC_FC_DIVIDE_LEVEL_NONE);

	/* Enable ADC */
	ADC_Enable(ADx);

}



/*********************************** END OF FILE ******************************/
