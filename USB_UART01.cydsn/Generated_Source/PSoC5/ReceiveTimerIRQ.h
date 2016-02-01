/*******************************************************************************
* File Name: ReceiveTimerIRQ.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_ReceiveTimerIRQ_H)
#define CY_ISR_ReceiveTimerIRQ_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void ReceiveTimerIRQ_Start(void);
void ReceiveTimerIRQ_StartEx(cyisraddress address);
void ReceiveTimerIRQ_Stop(void);

CY_ISR_PROTO(ReceiveTimerIRQ_Interrupt);

void ReceiveTimerIRQ_SetVector(cyisraddress address);
cyisraddress ReceiveTimerIRQ_GetVector(void);

void ReceiveTimerIRQ_SetPriority(uint8 priority);
uint8 ReceiveTimerIRQ_GetPriority(void);

void ReceiveTimerIRQ_Enable(void);
uint8 ReceiveTimerIRQ_GetState(void);
void ReceiveTimerIRQ_Disable(void);

void ReceiveTimerIRQ_SetPending(void);
void ReceiveTimerIRQ_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the ReceiveTimerIRQ ISR. */
#define ReceiveTimerIRQ_INTC_VECTOR            ((reg32 *) ReceiveTimerIRQ__INTC_VECT)

/* Address of the ReceiveTimerIRQ ISR priority. */
#define ReceiveTimerIRQ_INTC_PRIOR             ((reg8 *) ReceiveTimerIRQ__INTC_PRIOR_REG)

/* Priority of the ReceiveTimerIRQ interrupt. */
#define ReceiveTimerIRQ_INTC_PRIOR_NUMBER      ReceiveTimerIRQ__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable ReceiveTimerIRQ interrupt. */
#define ReceiveTimerIRQ_INTC_SET_EN            ((reg32 *) ReceiveTimerIRQ__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the ReceiveTimerIRQ interrupt. */
#define ReceiveTimerIRQ_INTC_CLR_EN            ((reg32 *) ReceiveTimerIRQ__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the ReceiveTimerIRQ interrupt state to pending. */
#define ReceiveTimerIRQ_INTC_SET_PD            ((reg32 *) ReceiveTimerIRQ__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the ReceiveTimerIRQ interrupt. */
#define ReceiveTimerIRQ_INTC_CLR_PD            ((reg32 *) ReceiveTimerIRQ__INTC_CLR_PD_REG)


#endif /* CY_ISR_ReceiveTimerIRQ_H */


/* [] END OF FILE */
