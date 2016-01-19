/*******************************************************************************
* File Name: Idle_Collision_IRQ.h
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
#if !defined(CY_ISR_Idle_Collision_IRQ_H)
#define CY_ISR_Idle_Collision_IRQ_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Idle_Collision_IRQ_Start(void);
void Idle_Collision_IRQ_StartEx(cyisraddress address);
void Idle_Collision_IRQ_Stop(void);

CY_ISR_PROTO(Idle_Collision_IRQ_Interrupt);

void Idle_Collision_IRQ_SetVector(cyisraddress address);
cyisraddress Idle_Collision_IRQ_GetVector(void);

void Idle_Collision_IRQ_SetPriority(uint8 priority);
uint8 Idle_Collision_IRQ_GetPriority(void);

void Idle_Collision_IRQ_Enable(void);
uint8 Idle_Collision_IRQ_GetState(void);
void Idle_Collision_IRQ_Disable(void);

void Idle_Collision_IRQ_SetPending(void);
void Idle_Collision_IRQ_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Idle_Collision_IRQ ISR. */
#define Idle_Collision_IRQ_INTC_VECTOR            ((reg32 *) Idle_Collision_IRQ__INTC_VECT)

/* Address of the Idle_Collision_IRQ ISR priority. */
#define Idle_Collision_IRQ_INTC_PRIOR             ((reg8 *) Idle_Collision_IRQ__INTC_PRIOR_REG)

/* Priority of the Idle_Collision_IRQ interrupt. */
#define Idle_Collision_IRQ_INTC_PRIOR_NUMBER      Idle_Collision_IRQ__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Idle_Collision_IRQ interrupt. */
#define Idle_Collision_IRQ_INTC_SET_EN            ((reg32 *) Idle_Collision_IRQ__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Idle_Collision_IRQ interrupt. */
#define Idle_Collision_IRQ_INTC_CLR_EN            ((reg32 *) Idle_Collision_IRQ__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Idle_Collision_IRQ interrupt state to pending. */
#define Idle_Collision_IRQ_INTC_SET_PD            ((reg32 *) Idle_Collision_IRQ__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Idle_Collision_IRQ interrupt. */
#define Idle_Collision_IRQ_INTC_CLR_PD            ((reg32 *) Idle_Collision_IRQ__INTC_CLR_PD_REG)


#endif /* CY_ISR_Idle_Collision_IRQ_H */


/* [] END OF FILE */
