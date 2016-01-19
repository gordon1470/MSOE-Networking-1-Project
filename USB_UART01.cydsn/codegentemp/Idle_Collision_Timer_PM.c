/*******************************************************************************
* File Name: Idle_Collision_Timer_PM.c
* Version 2.70
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Idle_Collision_Timer.h"

static Idle_Collision_Timer_backupStruct Idle_Collision_Timer_backup;


/*******************************************************************************
* Function Name: Idle_Collision_Timer_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Idle_Collision_Timer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Idle_Collision_Timer_SaveConfig(void) 
{
    #if (!Idle_Collision_Timer_UsingFixedFunction)
        Idle_Collision_Timer_backup.TimerUdb = Idle_Collision_Timer_ReadCounter();
        Idle_Collision_Timer_backup.InterruptMaskValue = Idle_Collision_Timer_STATUS_MASK;
        #if (Idle_Collision_Timer_UsingHWCaptureCounter)
            Idle_Collision_Timer_backup.TimerCaptureCounter = Idle_Collision_Timer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Idle_Collision_Timer_UDB_CONTROL_REG_REMOVED)
            Idle_Collision_Timer_backup.TimerControlRegister = Idle_Collision_Timer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Idle_Collision_Timer_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Idle_Collision_Timer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Idle_Collision_Timer_RestoreConfig(void) 
{   
    #if (!Idle_Collision_Timer_UsingFixedFunction)

        Idle_Collision_Timer_WriteCounter(Idle_Collision_Timer_backup.TimerUdb);
        Idle_Collision_Timer_STATUS_MASK =Idle_Collision_Timer_backup.InterruptMaskValue;
        #if (Idle_Collision_Timer_UsingHWCaptureCounter)
            Idle_Collision_Timer_SetCaptureCount(Idle_Collision_Timer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Idle_Collision_Timer_UDB_CONTROL_REG_REMOVED)
            Idle_Collision_Timer_WriteControlRegister(Idle_Collision_Timer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Idle_Collision_Timer_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Idle_Collision_Timer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Idle_Collision_Timer_Sleep(void) 
{
    #if(!Idle_Collision_Timer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Idle_Collision_Timer_CTRL_ENABLE == (Idle_Collision_Timer_CONTROL & Idle_Collision_Timer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Idle_Collision_Timer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Idle_Collision_Timer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Idle_Collision_Timer_Stop();
    Idle_Collision_Timer_SaveConfig();
}


/*******************************************************************************
* Function Name: Idle_Collision_Timer_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Idle_Collision_Timer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Idle_Collision_Timer_Wakeup(void) 
{
    Idle_Collision_Timer_RestoreConfig();
    #if(!Idle_Collision_Timer_UDB_CONTROL_REG_REMOVED)
        if(Idle_Collision_Timer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Idle_Collision_Timer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
