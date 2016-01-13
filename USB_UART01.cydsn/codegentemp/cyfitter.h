#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* LCD_LCDPort */
#define LCD_LCDPort__0__INTTYPE CYREG_PICU2_INTTYPE0
#define LCD_LCDPort__0__MASK 0x01u
#define LCD_LCDPort__0__PC CYREG_PRT2_PC0
#define LCD_LCDPort__0__PORT 2u
#define LCD_LCDPort__0__SHIFT 0
#define LCD_LCDPort__1__INTTYPE CYREG_PICU2_INTTYPE1
#define LCD_LCDPort__1__MASK 0x02u
#define LCD_LCDPort__1__PC CYREG_PRT2_PC1
#define LCD_LCDPort__1__PORT 2u
#define LCD_LCDPort__1__SHIFT 1
#define LCD_LCDPort__2__INTTYPE CYREG_PICU2_INTTYPE2
#define LCD_LCDPort__2__MASK 0x04u
#define LCD_LCDPort__2__PC CYREG_PRT2_PC2
#define LCD_LCDPort__2__PORT 2u
#define LCD_LCDPort__2__SHIFT 2
#define LCD_LCDPort__3__INTTYPE CYREG_PICU2_INTTYPE3
#define LCD_LCDPort__3__MASK 0x08u
#define LCD_LCDPort__3__PC CYREG_PRT2_PC3
#define LCD_LCDPort__3__PORT 2u
#define LCD_LCDPort__3__SHIFT 3
#define LCD_LCDPort__4__INTTYPE CYREG_PICU2_INTTYPE4
#define LCD_LCDPort__4__MASK 0x10u
#define LCD_LCDPort__4__PC CYREG_PRT2_PC4
#define LCD_LCDPort__4__PORT 2u
#define LCD_LCDPort__4__SHIFT 4
#define LCD_LCDPort__5__INTTYPE CYREG_PICU2_INTTYPE5
#define LCD_LCDPort__5__MASK 0x20u
#define LCD_LCDPort__5__PC CYREG_PRT2_PC5
#define LCD_LCDPort__5__PORT 2u
#define LCD_LCDPort__5__SHIFT 5
#define LCD_LCDPort__6__INTTYPE CYREG_PICU2_INTTYPE6
#define LCD_LCDPort__6__MASK 0x40u
#define LCD_LCDPort__6__PC CYREG_PRT2_PC6
#define LCD_LCDPort__6__PORT 2u
#define LCD_LCDPort__6__SHIFT 6
#define LCD_LCDPort__AG CYREG_PRT2_AG
#define LCD_LCDPort__AMUX CYREG_PRT2_AMUX
#define LCD_LCDPort__BIE CYREG_PRT2_BIE
#define LCD_LCDPort__BIT_MASK CYREG_PRT2_BIT_MASK
#define LCD_LCDPort__BYP CYREG_PRT2_BYP
#define LCD_LCDPort__CTL CYREG_PRT2_CTL
#define LCD_LCDPort__DM0 CYREG_PRT2_DM0
#define LCD_LCDPort__DM1 CYREG_PRT2_DM1
#define LCD_LCDPort__DM2 CYREG_PRT2_DM2
#define LCD_LCDPort__DR CYREG_PRT2_DR
#define LCD_LCDPort__INP_DIS CYREG_PRT2_INP_DIS
#define LCD_LCDPort__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define LCD_LCDPort__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define LCD_LCDPort__LCD_EN CYREG_PRT2_LCD_EN
#define LCD_LCDPort__MASK 0x7Fu
#define LCD_LCDPort__PORT 2u
#define LCD_LCDPort__PRT CYREG_PRT2_PRT
#define LCD_LCDPort__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define LCD_LCDPort__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define LCD_LCDPort__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define LCD_LCDPort__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define LCD_LCDPort__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define LCD_LCDPort__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define LCD_LCDPort__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define LCD_LCDPort__PS CYREG_PRT2_PS
#define LCD_LCDPort__SHIFT 0
#define LCD_LCDPort__SLW CYREG_PRT2_SLW

/* led4 */
#define led4__0__INTTYPE CYREG_PICU6_INTTYPE3
#define led4__0__MASK 0x08u
#define led4__0__PC CYREG_PRT6_PC3
#define led4__0__PORT 6u
#define led4__0__SHIFT 3
#define led4__AG CYREG_PRT6_AG
#define led4__AMUX CYREG_PRT6_AMUX
#define led4__BIE CYREG_PRT6_BIE
#define led4__BIT_MASK CYREG_PRT6_BIT_MASK
#define led4__BYP CYREG_PRT6_BYP
#define led4__CTL CYREG_PRT6_CTL
#define led4__DM0 CYREG_PRT6_DM0
#define led4__DM1 CYREG_PRT6_DM1
#define led4__DM2 CYREG_PRT6_DM2
#define led4__DR CYREG_PRT6_DR
#define led4__INP_DIS CYREG_PRT6_INP_DIS
#define led4__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU6_BASE
#define led4__LCD_COM_SEG CYREG_PRT6_LCD_COM_SEG
#define led4__LCD_EN CYREG_PRT6_LCD_EN
#define led4__MASK 0x08u
#define led4__PORT 6u
#define led4__PRT CYREG_PRT6_PRT
#define led4__PRTDSI__CAPS_SEL CYREG_PRT6_CAPS_SEL
#define led4__PRTDSI__DBL_SYNC_IN CYREG_PRT6_DBL_SYNC_IN
#define led4__PRTDSI__OE_SEL0 CYREG_PRT6_OE_SEL0
#define led4__PRTDSI__OE_SEL1 CYREG_PRT6_OE_SEL1
#define led4__PRTDSI__OUT_SEL0 CYREG_PRT6_OUT_SEL0
#define led4__PRTDSI__OUT_SEL1 CYREG_PRT6_OUT_SEL1
#define led4__PRTDSI__SYNC_OUT CYREG_PRT6_SYNC_OUT
#define led4__PS CYREG_PRT6_PS
#define led4__SHIFT 3
#define led4__SLW CYREG_PRT6_SLW

/* Timer_TimerUDB */
#define Timer_TimerUDB_rstSts_stsreg__0__MASK 0x01u
#define Timer_TimerUDB_rstSts_stsreg__0__POS 0
#define Timer_TimerUDB_rstSts_stsreg__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB11_12_ACTL
#define Timer_TimerUDB_rstSts_stsreg__16BIT_STATUS_REG CYREG_B0_UDB11_12_ST
#define Timer_TimerUDB_rstSts_stsreg__2__MASK 0x04u
#define Timer_TimerUDB_rstSts_stsreg__2__POS 2
#define Timer_TimerUDB_rstSts_stsreg__3__MASK 0x08u
#define Timer_TimerUDB_rstSts_stsreg__3__POS 3
#define Timer_TimerUDB_rstSts_stsreg__MASK 0x0Du
#define Timer_TimerUDB_rstSts_stsreg__MASK_REG CYREG_B0_UDB11_MSK
#define Timer_TimerUDB_rstSts_stsreg__MASK_ST_AUX_CTL_REG CYREG_B0_UDB11_MSK_ACTL
#define Timer_TimerUDB_rstSts_stsreg__PER_ST_AUX_CTL_REG CYREG_B0_UDB11_MSK_ACTL
#define Timer_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG CYREG_B0_UDB11_ACTL
#define Timer_TimerUDB_rstSts_stsreg__STATUS_CNT_REG CYREG_B0_UDB11_ST_CTL
#define Timer_TimerUDB_rstSts_stsreg__STATUS_CONTROL_REG CYREG_B0_UDB11_ST_CTL
#define Timer_TimerUDB_rstSts_stsreg__STATUS_REG CYREG_B0_UDB11_ST
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB11_12_ACTL
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB11_12_CTL
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB11_12_CTL
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB11_12_CTL
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_COUNT_REG CYREG_B0_UDB11_12_CTL
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_MASK_REG CYREG_B0_UDB11_12_MSK
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_PERIOD_REG CYREG_B0_UDB11_12_MSK
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_MASK_REG CYREG_B0_UDB11_12_MSK
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB11_12_MSK
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__MASK 0x80u
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__POS 7
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_AUX_CTL_REG CYREG_B0_UDB11_ACTL
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG CYREG_B0_UDB11_CTL
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_ST_REG CYREG_B0_UDB11_ST_CTL
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_REG CYREG_B0_UDB11_CTL
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_ST_REG CYREG_B0_UDB11_ST_CTL
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK 0x80u
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB11_MSK_ACTL
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB11_MSK_ACTL
#define Timer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PERIOD_REG CYREG_B0_UDB11_MSK
#define Timer_TimerUDB_sT16_timerdp_u0__16BIT_A0_REG CYREG_B0_UDB10_11_A0
#define Timer_TimerUDB_sT16_timerdp_u0__16BIT_A1_REG CYREG_B0_UDB10_11_A1
#define Timer_TimerUDB_sT16_timerdp_u0__16BIT_D0_REG CYREG_B0_UDB10_11_D0
#define Timer_TimerUDB_sT16_timerdp_u0__16BIT_D1_REG CYREG_B0_UDB10_11_D1
#define Timer_TimerUDB_sT16_timerdp_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB10_11_ACTL
#define Timer_TimerUDB_sT16_timerdp_u0__16BIT_F0_REG CYREG_B0_UDB10_11_F0
#define Timer_TimerUDB_sT16_timerdp_u0__16BIT_F1_REG CYREG_B0_UDB10_11_F1
#define Timer_TimerUDB_sT16_timerdp_u0__A0_A1_REG CYREG_B0_UDB10_A0_A1
#define Timer_TimerUDB_sT16_timerdp_u0__A0_REG CYREG_B0_UDB10_A0
#define Timer_TimerUDB_sT16_timerdp_u0__A1_REG CYREG_B0_UDB10_A1
#define Timer_TimerUDB_sT16_timerdp_u0__D0_D1_REG CYREG_B0_UDB10_D0_D1
#define Timer_TimerUDB_sT16_timerdp_u0__D0_REG CYREG_B0_UDB10_D0
#define Timer_TimerUDB_sT16_timerdp_u0__D1_REG CYREG_B0_UDB10_D1
#define Timer_TimerUDB_sT16_timerdp_u0__DP_AUX_CTL_REG CYREG_B0_UDB10_ACTL
#define Timer_TimerUDB_sT16_timerdp_u0__F0_F1_REG CYREG_B0_UDB10_F0_F1
#define Timer_TimerUDB_sT16_timerdp_u0__F0_REG CYREG_B0_UDB10_F0
#define Timer_TimerUDB_sT16_timerdp_u0__F1_REG CYREG_B0_UDB10_F1
#define Timer_TimerUDB_sT16_timerdp_u1__16BIT_A0_REG CYREG_B0_UDB11_12_A0
#define Timer_TimerUDB_sT16_timerdp_u1__16BIT_A1_REG CYREG_B0_UDB11_12_A1
#define Timer_TimerUDB_sT16_timerdp_u1__16BIT_D0_REG CYREG_B0_UDB11_12_D0
#define Timer_TimerUDB_sT16_timerdp_u1__16BIT_D1_REG CYREG_B0_UDB11_12_D1
#define Timer_TimerUDB_sT16_timerdp_u1__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB11_12_ACTL
#define Timer_TimerUDB_sT16_timerdp_u1__16BIT_F0_REG CYREG_B0_UDB11_12_F0
#define Timer_TimerUDB_sT16_timerdp_u1__16BIT_F1_REG CYREG_B0_UDB11_12_F1
#define Timer_TimerUDB_sT16_timerdp_u1__A0_A1_REG CYREG_B0_UDB11_A0_A1
#define Timer_TimerUDB_sT16_timerdp_u1__A0_REG CYREG_B0_UDB11_A0
#define Timer_TimerUDB_sT16_timerdp_u1__A1_REG CYREG_B0_UDB11_A1
#define Timer_TimerUDB_sT16_timerdp_u1__D0_D1_REG CYREG_B0_UDB11_D0_D1
#define Timer_TimerUDB_sT16_timerdp_u1__D0_REG CYREG_B0_UDB11_D0
#define Timer_TimerUDB_sT16_timerdp_u1__D1_REG CYREG_B0_UDB11_D1
#define Timer_TimerUDB_sT16_timerdp_u1__DP_AUX_CTL_REG CYREG_B0_UDB11_ACTL
#define Timer_TimerUDB_sT16_timerdp_u1__F0_F1_REG CYREG_B0_UDB11_F0_F1
#define Timer_TimerUDB_sT16_timerdp_u1__F0_REG CYREG_B0_UDB11_F0
#define Timer_TimerUDB_sT16_timerdp_u1__F1_REG CYREG_B0_UDB11_F1
#define Timer_TimerUDB_sT16_timerdp_u1__MSK_DP_AUX_CTL_REG CYREG_B0_UDB11_MSK_ACTL
#define Timer_TimerUDB_sT16_timerdp_u1__PER_DP_AUX_CTL_REG CYREG_B0_UDB11_MSK_ACTL

/* TX_pin */
#define TX_pin__0__INTTYPE CYREG_PICU12_INTTYPE4
#define TX_pin__0__MASK 0x10u
#define TX_pin__0__PC CYREG_PRT12_PC4
#define TX_pin__0__PORT 12u
#define TX_pin__0__SHIFT 4
#define TX_pin__AG CYREG_PRT12_AG
#define TX_pin__BIE CYREG_PRT12_BIE
#define TX_pin__BIT_MASK CYREG_PRT12_BIT_MASK
#define TX_pin__BYP CYREG_PRT12_BYP
#define TX_pin__DM0 CYREG_PRT12_DM0
#define TX_pin__DM1 CYREG_PRT12_DM1
#define TX_pin__DM2 CYREG_PRT12_DM2
#define TX_pin__DR CYREG_PRT12_DR
#define TX_pin__INP_DIS CYREG_PRT12_INP_DIS
#define TX_pin__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU12_BASE
#define TX_pin__MASK 0x10u
#define TX_pin__PORT 12u
#define TX_pin__PRT CYREG_PRT12_PRT
#define TX_pin__PRTDSI__DBL_SYNC_IN CYREG_PRT12_DBL_SYNC_IN
#define TX_pin__PRTDSI__OE_SEL0 CYREG_PRT12_OE_SEL0
#define TX_pin__PRTDSI__OE_SEL1 CYREG_PRT12_OE_SEL1
#define TX_pin__PRTDSI__OUT_SEL0 CYREG_PRT12_OUT_SEL0
#define TX_pin__PRTDSI__OUT_SEL1 CYREG_PRT12_OUT_SEL1
#define TX_pin__PRTDSI__SYNC_OUT CYREG_PRT12_SYNC_OUT
#define TX_pin__PS CYREG_PRT12_PS
#define TX_pin__SHIFT 4
#define TX_pin__SIO_CFG CYREG_PRT12_SIO_CFG
#define TX_pin__SIO_DIFF CYREG_PRT12_SIO_DIFF
#define TX_pin__SIO_HYST_EN CYREG_PRT12_SIO_HYST_EN
#define TX_pin__SIO_REG_HIFREQ CYREG_PRT12_SIO_REG_HIFREQ
#define TX_pin__SLW CYREG_PRT12_SLW

/* TimerISR */
#define TimerISR__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define TimerISR__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define TimerISR__INTC_MASK 0x01u
#define TimerISR__INTC_NUMBER 0u
#define TimerISR__INTC_PRIOR_NUM 7u
#define TimerISR__INTC_PRIOR_REG CYREG_NVIC_PRI_0
#define TimerISR__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define TimerISR__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* USBUART_1_arb_int */
#define USBUART_1_arb_int__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define USBUART_1_arb_int__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define USBUART_1_arb_int__INTC_MASK 0x400000u
#define USBUART_1_arb_int__INTC_NUMBER 22u
#define USBUART_1_arb_int__INTC_PRIOR_NUM 7u
#define USBUART_1_arb_int__INTC_PRIOR_REG CYREG_NVIC_PRI_22
#define USBUART_1_arb_int__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define USBUART_1_arb_int__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* USBUART_1_bus_reset */
#define USBUART_1_bus_reset__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define USBUART_1_bus_reset__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define USBUART_1_bus_reset__INTC_MASK 0x800000u
#define USBUART_1_bus_reset__INTC_NUMBER 23u
#define USBUART_1_bus_reset__INTC_PRIOR_NUM 7u
#define USBUART_1_bus_reset__INTC_PRIOR_REG CYREG_NVIC_PRI_23
#define USBUART_1_bus_reset__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define USBUART_1_bus_reset__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* USBUART_1_Dm */
#define USBUART_1_Dm__0__INTTYPE CYREG_PICU15_INTTYPE7
#define USBUART_1_Dm__0__MASK 0x80u
#define USBUART_1_Dm__0__PC CYREG_IO_PC_PRT15_7_6_PC1
#define USBUART_1_Dm__0__PORT 15u
#define USBUART_1_Dm__0__SHIFT 7
#define USBUART_1_Dm__AG CYREG_PRT15_AG
#define USBUART_1_Dm__AMUX CYREG_PRT15_AMUX
#define USBUART_1_Dm__BIE CYREG_PRT15_BIE
#define USBUART_1_Dm__BIT_MASK CYREG_PRT15_BIT_MASK
#define USBUART_1_Dm__BYP CYREG_PRT15_BYP
#define USBUART_1_Dm__CTL CYREG_PRT15_CTL
#define USBUART_1_Dm__DM0 CYREG_PRT15_DM0
#define USBUART_1_Dm__DM1 CYREG_PRT15_DM1
#define USBUART_1_Dm__DM2 CYREG_PRT15_DM2
#define USBUART_1_Dm__DR CYREG_PRT15_DR
#define USBUART_1_Dm__INP_DIS CYREG_PRT15_INP_DIS
#define USBUART_1_Dm__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU15_BASE
#define USBUART_1_Dm__LCD_COM_SEG CYREG_PRT15_LCD_COM_SEG
#define USBUART_1_Dm__LCD_EN CYREG_PRT15_LCD_EN
#define USBUART_1_Dm__MASK 0x80u
#define USBUART_1_Dm__PORT 15u
#define USBUART_1_Dm__PRT CYREG_PRT15_PRT
#define USBUART_1_Dm__PRTDSI__CAPS_SEL CYREG_PRT15_CAPS_SEL
#define USBUART_1_Dm__PRTDSI__DBL_SYNC_IN CYREG_PRT15_DBL_SYNC_IN
#define USBUART_1_Dm__PRTDSI__OE_SEL0 CYREG_PRT15_OE_SEL0
#define USBUART_1_Dm__PRTDSI__OE_SEL1 CYREG_PRT15_OE_SEL1
#define USBUART_1_Dm__PRTDSI__OUT_SEL0 CYREG_PRT15_OUT_SEL0
#define USBUART_1_Dm__PRTDSI__OUT_SEL1 CYREG_PRT15_OUT_SEL1
#define USBUART_1_Dm__PRTDSI__SYNC_OUT CYREG_PRT15_SYNC_OUT
#define USBUART_1_Dm__PS CYREG_PRT15_PS
#define USBUART_1_Dm__SHIFT 7
#define USBUART_1_Dm__SLW CYREG_PRT15_SLW

/* USBUART_1_Dp */
#define USBUART_1_Dp__0__INTTYPE CYREG_PICU15_INTTYPE6
#define USBUART_1_Dp__0__MASK 0x40u
#define USBUART_1_Dp__0__PC CYREG_IO_PC_PRT15_7_6_PC0
#define USBUART_1_Dp__0__PORT 15u
#define USBUART_1_Dp__0__SHIFT 6
#define USBUART_1_Dp__AG CYREG_PRT15_AG
#define USBUART_1_Dp__AMUX CYREG_PRT15_AMUX
#define USBUART_1_Dp__BIE CYREG_PRT15_BIE
#define USBUART_1_Dp__BIT_MASK CYREG_PRT15_BIT_MASK
#define USBUART_1_Dp__BYP CYREG_PRT15_BYP
#define USBUART_1_Dp__CTL CYREG_PRT15_CTL
#define USBUART_1_Dp__DM0 CYREG_PRT15_DM0
#define USBUART_1_Dp__DM1 CYREG_PRT15_DM1
#define USBUART_1_Dp__DM2 CYREG_PRT15_DM2
#define USBUART_1_Dp__DR CYREG_PRT15_DR
#define USBUART_1_Dp__INP_DIS CYREG_PRT15_INP_DIS
#define USBUART_1_Dp__INTSTAT CYREG_PICU15_INTSTAT
#define USBUART_1_Dp__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU15_BASE
#define USBUART_1_Dp__LCD_COM_SEG CYREG_PRT15_LCD_COM_SEG
#define USBUART_1_Dp__LCD_EN CYREG_PRT15_LCD_EN
#define USBUART_1_Dp__MASK 0x40u
#define USBUART_1_Dp__PORT 15u
#define USBUART_1_Dp__PRT CYREG_PRT15_PRT
#define USBUART_1_Dp__PRTDSI__CAPS_SEL CYREG_PRT15_CAPS_SEL
#define USBUART_1_Dp__PRTDSI__DBL_SYNC_IN CYREG_PRT15_DBL_SYNC_IN
#define USBUART_1_Dp__PRTDSI__OE_SEL0 CYREG_PRT15_OE_SEL0
#define USBUART_1_Dp__PRTDSI__OE_SEL1 CYREG_PRT15_OE_SEL1
#define USBUART_1_Dp__PRTDSI__OUT_SEL0 CYREG_PRT15_OUT_SEL0
#define USBUART_1_Dp__PRTDSI__OUT_SEL1 CYREG_PRT15_OUT_SEL1
#define USBUART_1_Dp__PRTDSI__SYNC_OUT CYREG_PRT15_SYNC_OUT
#define USBUART_1_Dp__PS CYREG_PRT15_PS
#define USBUART_1_Dp__SHIFT 6
#define USBUART_1_Dp__SLW CYREG_PRT15_SLW
#define USBUART_1_Dp__SNAP CYREG_PICU_15_SNAP_15

/* USBUART_1_dp_int */
#define USBUART_1_dp_int__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define USBUART_1_dp_int__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define USBUART_1_dp_int__INTC_MASK 0x1000u
#define USBUART_1_dp_int__INTC_NUMBER 12u
#define USBUART_1_dp_int__INTC_PRIOR_NUM 7u
#define USBUART_1_dp_int__INTC_PRIOR_REG CYREG_NVIC_PRI_12
#define USBUART_1_dp_int__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define USBUART_1_dp_int__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* USBUART_1_ep_0 */
#define USBUART_1_ep_0__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define USBUART_1_ep_0__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define USBUART_1_ep_0__INTC_MASK 0x1000000u
#define USBUART_1_ep_0__INTC_NUMBER 24u
#define USBUART_1_ep_0__INTC_PRIOR_NUM 7u
#define USBUART_1_ep_0__INTC_PRIOR_REG CYREG_NVIC_PRI_24
#define USBUART_1_ep_0__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define USBUART_1_ep_0__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* USBUART_1_ep_1 */
#define USBUART_1_ep_1__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define USBUART_1_ep_1__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define USBUART_1_ep_1__INTC_MASK 0x02u
#define USBUART_1_ep_1__INTC_NUMBER 1u
#define USBUART_1_ep_1__INTC_PRIOR_NUM 7u
#define USBUART_1_ep_1__INTC_PRIOR_REG CYREG_NVIC_PRI_1
#define USBUART_1_ep_1__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define USBUART_1_ep_1__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* USBUART_1_ep_2 */
#define USBUART_1_ep_2__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define USBUART_1_ep_2__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define USBUART_1_ep_2__INTC_MASK 0x04u
#define USBUART_1_ep_2__INTC_NUMBER 2u
#define USBUART_1_ep_2__INTC_PRIOR_NUM 7u
#define USBUART_1_ep_2__INTC_PRIOR_REG CYREG_NVIC_PRI_2
#define USBUART_1_ep_2__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define USBUART_1_ep_2__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* USBUART_1_ep_3 */
#define USBUART_1_ep_3__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define USBUART_1_ep_3__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define USBUART_1_ep_3__INTC_MASK 0x08u
#define USBUART_1_ep_3__INTC_NUMBER 3u
#define USBUART_1_ep_3__INTC_PRIOR_NUM 7u
#define USBUART_1_ep_3__INTC_PRIOR_REG CYREG_NVIC_PRI_3
#define USBUART_1_ep_3__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define USBUART_1_ep_3__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* USBUART_1_ord_int */
#define USBUART_1_ord_int__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define USBUART_1_ord_int__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define USBUART_1_ord_int__INTC_MASK 0x2000000u
#define USBUART_1_ord_int__INTC_NUMBER 25u
#define USBUART_1_ord_int__INTC_PRIOR_NUM 7u
#define USBUART_1_ord_int__INTC_PRIOR_REG CYREG_NVIC_PRI_25
#define USBUART_1_ord_int__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define USBUART_1_ord_int__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* USBUART_1_sof_int */
#define USBUART_1_sof_int__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define USBUART_1_sof_int__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define USBUART_1_sof_int__INTC_MASK 0x200000u
#define USBUART_1_sof_int__INTC_NUMBER 21u
#define USBUART_1_sof_int__INTC_PRIOR_NUM 7u
#define USBUART_1_sof_int__INTC_PRIOR_REG CYREG_NVIC_PRI_21
#define USBUART_1_sof_int__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define USBUART_1_sof_int__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* USBUART_1_USB */
#define USBUART_1_USB__ARB_CFG CYREG_USB_ARB_CFG
#define USBUART_1_USB__ARB_EP1_CFG CYREG_USB_ARB_EP1_CFG
#define USBUART_1_USB__ARB_EP1_INT_EN CYREG_USB_ARB_EP1_INT_EN
#define USBUART_1_USB__ARB_EP1_SR CYREG_USB_ARB_EP1_SR
#define USBUART_1_USB__ARB_EP2_CFG CYREG_USB_ARB_EP2_CFG
#define USBUART_1_USB__ARB_EP2_INT_EN CYREG_USB_ARB_EP2_INT_EN
#define USBUART_1_USB__ARB_EP2_SR CYREG_USB_ARB_EP2_SR
#define USBUART_1_USB__ARB_EP3_CFG CYREG_USB_ARB_EP3_CFG
#define USBUART_1_USB__ARB_EP3_INT_EN CYREG_USB_ARB_EP3_INT_EN
#define USBUART_1_USB__ARB_EP3_SR CYREG_USB_ARB_EP3_SR
#define USBUART_1_USB__ARB_EP4_CFG CYREG_USB_ARB_EP4_CFG
#define USBUART_1_USB__ARB_EP4_INT_EN CYREG_USB_ARB_EP4_INT_EN
#define USBUART_1_USB__ARB_EP4_SR CYREG_USB_ARB_EP4_SR
#define USBUART_1_USB__ARB_EP5_CFG CYREG_USB_ARB_EP5_CFG
#define USBUART_1_USB__ARB_EP5_INT_EN CYREG_USB_ARB_EP5_INT_EN
#define USBUART_1_USB__ARB_EP5_SR CYREG_USB_ARB_EP5_SR
#define USBUART_1_USB__ARB_EP6_CFG CYREG_USB_ARB_EP6_CFG
#define USBUART_1_USB__ARB_EP6_INT_EN CYREG_USB_ARB_EP6_INT_EN
#define USBUART_1_USB__ARB_EP6_SR CYREG_USB_ARB_EP6_SR
#define USBUART_1_USB__ARB_EP7_CFG CYREG_USB_ARB_EP7_CFG
#define USBUART_1_USB__ARB_EP7_INT_EN CYREG_USB_ARB_EP7_INT_EN
#define USBUART_1_USB__ARB_EP7_SR CYREG_USB_ARB_EP7_SR
#define USBUART_1_USB__ARB_EP8_CFG CYREG_USB_ARB_EP8_CFG
#define USBUART_1_USB__ARB_EP8_INT_EN CYREG_USB_ARB_EP8_INT_EN
#define USBUART_1_USB__ARB_EP8_SR CYREG_USB_ARB_EP8_SR
#define USBUART_1_USB__ARB_INT_EN CYREG_USB_ARB_INT_EN
#define USBUART_1_USB__ARB_INT_SR CYREG_USB_ARB_INT_SR
#define USBUART_1_USB__ARB_RW1_DR CYREG_USB_ARB_RW1_DR
#define USBUART_1_USB__ARB_RW1_RA CYREG_USB_ARB_RW1_RA
#define USBUART_1_USB__ARB_RW1_RA_MSB CYREG_USB_ARB_RW1_RA_MSB
#define USBUART_1_USB__ARB_RW1_WA CYREG_USB_ARB_RW1_WA
#define USBUART_1_USB__ARB_RW1_WA_MSB CYREG_USB_ARB_RW1_WA_MSB
#define USBUART_1_USB__ARB_RW2_DR CYREG_USB_ARB_RW2_DR
#define USBUART_1_USB__ARB_RW2_RA CYREG_USB_ARB_RW2_RA
#define USBUART_1_USB__ARB_RW2_RA_MSB CYREG_USB_ARB_RW2_RA_MSB
#define USBUART_1_USB__ARB_RW2_WA CYREG_USB_ARB_RW2_WA
#define USBUART_1_USB__ARB_RW2_WA_MSB CYREG_USB_ARB_RW2_WA_MSB
#define USBUART_1_USB__ARB_RW3_DR CYREG_USB_ARB_RW3_DR
#define USBUART_1_USB__ARB_RW3_RA CYREG_USB_ARB_RW3_RA
#define USBUART_1_USB__ARB_RW3_RA_MSB CYREG_USB_ARB_RW3_RA_MSB
#define USBUART_1_USB__ARB_RW3_WA CYREG_USB_ARB_RW3_WA
#define USBUART_1_USB__ARB_RW3_WA_MSB CYREG_USB_ARB_RW3_WA_MSB
#define USBUART_1_USB__ARB_RW4_DR CYREG_USB_ARB_RW4_DR
#define USBUART_1_USB__ARB_RW4_RA CYREG_USB_ARB_RW4_RA
#define USBUART_1_USB__ARB_RW4_RA_MSB CYREG_USB_ARB_RW4_RA_MSB
#define USBUART_1_USB__ARB_RW4_WA CYREG_USB_ARB_RW4_WA
#define USBUART_1_USB__ARB_RW4_WA_MSB CYREG_USB_ARB_RW4_WA_MSB
#define USBUART_1_USB__ARB_RW5_DR CYREG_USB_ARB_RW5_DR
#define USBUART_1_USB__ARB_RW5_RA CYREG_USB_ARB_RW5_RA
#define USBUART_1_USB__ARB_RW5_RA_MSB CYREG_USB_ARB_RW5_RA_MSB
#define USBUART_1_USB__ARB_RW5_WA CYREG_USB_ARB_RW5_WA
#define USBUART_1_USB__ARB_RW5_WA_MSB CYREG_USB_ARB_RW5_WA_MSB
#define USBUART_1_USB__ARB_RW6_DR CYREG_USB_ARB_RW6_DR
#define USBUART_1_USB__ARB_RW6_RA CYREG_USB_ARB_RW6_RA
#define USBUART_1_USB__ARB_RW6_RA_MSB CYREG_USB_ARB_RW6_RA_MSB
#define USBUART_1_USB__ARB_RW6_WA CYREG_USB_ARB_RW6_WA
#define USBUART_1_USB__ARB_RW6_WA_MSB CYREG_USB_ARB_RW6_WA_MSB
#define USBUART_1_USB__ARB_RW7_DR CYREG_USB_ARB_RW7_DR
#define USBUART_1_USB__ARB_RW7_RA CYREG_USB_ARB_RW7_RA
#define USBUART_1_USB__ARB_RW7_RA_MSB CYREG_USB_ARB_RW7_RA_MSB
#define USBUART_1_USB__ARB_RW7_WA CYREG_USB_ARB_RW7_WA
#define USBUART_1_USB__ARB_RW7_WA_MSB CYREG_USB_ARB_RW7_WA_MSB
#define USBUART_1_USB__ARB_RW8_DR CYREG_USB_ARB_RW8_DR
#define USBUART_1_USB__ARB_RW8_RA CYREG_USB_ARB_RW8_RA
#define USBUART_1_USB__ARB_RW8_RA_MSB CYREG_USB_ARB_RW8_RA_MSB
#define USBUART_1_USB__ARB_RW8_WA CYREG_USB_ARB_RW8_WA
#define USBUART_1_USB__ARB_RW8_WA_MSB CYREG_USB_ARB_RW8_WA_MSB
#define USBUART_1_USB__BUF_SIZE CYREG_USB_BUF_SIZE
#define USBUART_1_USB__BUS_RST_CNT CYREG_USB_BUS_RST_CNT
#define USBUART_1_USB__CR0 CYREG_USB_CR0
#define USBUART_1_USB__CR1 CYREG_USB_CR1
#define USBUART_1_USB__CWA CYREG_USB_CWA
#define USBUART_1_USB__CWA_MSB CYREG_USB_CWA_MSB
#define USBUART_1_USB__DMA_THRES CYREG_USB_DMA_THRES
#define USBUART_1_USB__DMA_THRES_MSB CYREG_USB_DMA_THRES_MSB
#define USBUART_1_USB__DYN_RECONFIG CYREG_USB_DYN_RECONFIG
#define USBUART_1_USB__EP_ACTIVE CYREG_USB_EP_ACTIVE
#define USBUART_1_USB__EP_TYPE CYREG_USB_EP_TYPE
#define USBUART_1_USB__EP0_CNT CYREG_USB_EP0_CNT
#define USBUART_1_USB__EP0_CR CYREG_USB_EP0_CR
#define USBUART_1_USB__EP0_DR0 CYREG_USB_EP0_DR0
#define USBUART_1_USB__EP0_DR1 CYREG_USB_EP0_DR1
#define USBUART_1_USB__EP0_DR2 CYREG_USB_EP0_DR2
#define USBUART_1_USB__EP0_DR3 CYREG_USB_EP0_DR3
#define USBUART_1_USB__EP0_DR4 CYREG_USB_EP0_DR4
#define USBUART_1_USB__EP0_DR5 CYREG_USB_EP0_DR5
#define USBUART_1_USB__EP0_DR6 CYREG_USB_EP0_DR6
#define USBUART_1_USB__EP0_DR7 CYREG_USB_EP0_DR7
#define USBUART_1_USB__MEM_DATA CYREG_USB_MEM_DATA_MBASE
#define USBUART_1_USB__PM_ACT_CFG CYREG_PM_ACT_CFG5
#define USBUART_1_USB__PM_ACT_MSK 0x01u
#define USBUART_1_USB__PM_STBY_CFG CYREG_PM_STBY_CFG5
#define USBUART_1_USB__PM_STBY_MSK 0x01u
#define USBUART_1_USB__SIE_EP_INT_EN CYREG_USB_SIE_EP_INT_EN
#define USBUART_1_USB__SIE_EP_INT_SR CYREG_USB_SIE_EP_INT_SR
#define USBUART_1_USB__SIE_EP1_CNT0 CYREG_USB_SIE_EP1_CNT0
#define USBUART_1_USB__SIE_EP1_CNT1 CYREG_USB_SIE_EP1_CNT1
#define USBUART_1_USB__SIE_EP1_CR0 CYREG_USB_SIE_EP1_CR0
#define USBUART_1_USB__SIE_EP2_CNT0 CYREG_USB_SIE_EP2_CNT0
#define USBUART_1_USB__SIE_EP2_CNT1 CYREG_USB_SIE_EP2_CNT1
#define USBUART_1_USB__SIE_EP2_CR0 CYREG_USB_SIE_EP2_CR0
#define USBUART_1_USB__SIE_EP3_CNT0 CYREG_USB_SIE_EP3_CNT0
#define USBUART_1_USB__SIE_EP3_CNT1 CYREG_USB_SIE_EP3_CNT1
#define USBUART_1_USB__SIE_EP3_CR0 CYREG_USB_SIE_EP3_CR0
#define USBUART_1_USB__SIE_EP4_CNT0 CYREG_USB_SIE_EP4_CNT0
#define USBUART_1_USB__SIE_EP4_CNT1 CYREG_USB_SIE_EP4_CNT1
#define USBUART_1_USB__SIE_EP4_CR0 CYREG_USB_SIE_EP4_CR0
#define USBUART_1_USB__SIE_EP5_CNT0 CYREG_USB_SIE_EP5_CNT0
#define USBUART_1_USB__SIE_EP5_CNT1 CYREG_USB_SIE_EP5_CNT1
#define USBUART_1_USB__SIE_EP5_CR0 CYREG_USB_SIE_EP5_CR0
#define USBUART_1_USB__SIE_EP6_CNT0 CYREG_USB_SIE_EP6_CNT0
#define USBUART_1_USB__SIE_EP6_CNT1 CYREG_USB_SIE_EP6_CNT1
#define USBUART_1_USB__SIE_EP6_CR0 CYREG_USB_SIE_EP6_CR0
#define USBUART_1_USB__SIE_EP7_CNT0 CYREG_USB_SIE_EP7_CNT0
#define USBUART_1_USB__SIE_EP7_CNT1 CYREG_USB_SIE_EP7_CNT1
#define USBUART_1_USB__SIE_EP7_CR0 CYREG_USB_SIE_EP7_CR0
#define USBUART_1_USB__SIE_EP8_CNT0 CYREG_USB_SIE_EP8_CNT0
#define USBUART_1_USB__SIE_EP8_CNT1 CYREG_USB_SIE_EP8_CNT1
#define USBUART_1_USB__SIE_EP8_CR0 CYREG_USB_SIE_EP8_CR0
#define USBUART_1_USB__SOF0 CYREG_USB_SOF0
#define USBUART_1_USB__SOF1 CYREG_USB_SOF1
#define USBUART_1_USB__USB_CLK_EN CYREG_USB_USB_CLK_EN
#define USBUART_1_USB__USBIO_CR0 CYREG_USB_USBIO_CR0
#define USBUART_1_USB__USBIO_CR1 CYREG_USB_USBIO_CR1

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 64000000U
#define BCLK__BUS_CLK__KHZ 64000U
#define BCLK__BUS_CLK__MHZ 64U
#define CY_PROJECT_NAME "USB_UART01"
#define CY_VERSION "PSoC Creator  3.3 CP1"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PANTHER 18u
#define CYDEV_CHIP_DIE_PSOC4A 10u
#define CYDEV_CHIP_DIE_PSOC5LP 17u
#define CYDEV_CHIP_DIE_TMA4 2u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E123069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 10u
#define CYDEV_CHIP_MEMBER_4C 15u
#define CYDEV_CHIP_MEMBER_4D 6u
#define CYDEV_CHIP_MEMBER_4E 4u
#define CYDEV_CHIP_MEMBER_4F 11u
#define CYDEV_CHIP_MEMBER_4G 2u
#define CYDEV_CHIP_MEMBER_4H 9u
#define CYDEV_CHIP_MEMBER_4I 14u
#define CYDEV_CHIP_MEMBER_4J 7u
#define CYDEV_CHIP_MEMBER_4K 8u
#define CYDEV_CHIP_MEMBER_4L 13u
#define CYDEV_CHIP_MEMBER_4M 12u
#define CYDEV_CHIP_MEMBER_4N 5u
#define CYDEV_CHIP_MEMBER_4U 3u
#define CYDEV_CHIP_MEMBER_5A 17u
#define CYDEV_CHIP_MEMBER_5B 16u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PANTHER_ES0 0u
#define CYDEV_CHIP_REV_PANTHER_ES1 1u
#define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4C_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 0
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 1
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_INSTRUCT_CACHE_ENABLED 0
#define CYDEV_INTR_RISING 0x00000001u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USB_CLK_OSC_LOCKING_ENABLED_AT_PWR_UP 
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 3.3
#define CYDEV_VDDA_MV 3300
#define CYDEV_VDDD 3.3
#define CYDEV_VDDD_MV 3300
#define CYDEV_VDDIO0 3.3
#define CYDEV_VDDIO0_MV 3300
#define CYDEV_VDDIO1 3.3
#define CYDEV_VDDIO1_MV 3300
#define CYDEV_VDDIO2 3.3
#define CYDEV_VDDIO2_MV 3300
#define CYDEV_VDDIO3 3.3
#define CYDEV_VDDIO3_MV 3300
#define CYDEV_VIO0 3.3
#define CYDEV_VIO0_MV 3300
#define CYDEV_VIO1 3.3
#define CYDEV_VIO1_MV 3300
#define CYDEV_VIO2 3.3
#define CYDEV_VIO2_MV 3300
#define CYDEV_VIO3 3.3
#define CYDEV_VIO3_MV 3300
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x00000000u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
