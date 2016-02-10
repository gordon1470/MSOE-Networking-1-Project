/*******************************************************************************
* File Name: Receive_Timer_PM.c
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

#include "Receive_Timer.h"

static Receive_Timer_backupStruct Receive_Timer_backup;


/*******************************************************************************
* Function Name: Receive_Timer_SaveConfig
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
*  Receive_Timer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Receive_Timer_SaveConfig(void) 
{
    #if (!Receive_Timer_UsingFixedFunction)
        Receive_Timer_backup.TimerUdb = Receive_Timer_ReadCounter();
        Receive_Timer_backup.InterruptMaskValue = Receive_Timer_STATUS_MASK;
        #if (Receive_Timer_UsingHWCaptureCounter)
            Receive_Timer_backup.TimerCaptureCounter = Receive_Timer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Receive_Timer_UDB_CONTROL_REG_REMOVED)
            Receive_Timer_backup.TimerControlRegister = Receive_Timer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Receive_Timer_RestoreConfig
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
*  Receive_Timer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Receive_Timer_RestoreConfig(void) 
{   
    #if (!Receive_Timer_UsingFixedFunction)

        Receive_Timer_WriteCounter(Receive_Timer_backup.TimerUdb);
        Receive_Timer_STATUS_MASK =Receive_Timer_backup.InterruptMaskValue;
        #if (Receive_Timer_UsingHWCaptureCounter)
            Receive_Timer_SetCaptureCount(Receive_Timer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Receive_Timer_UDB_CONTROL_REG_REMOVED)
            Receive_Timer_WriteControlRegister(Receive_Timer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Receive_Timer_Sleep
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
*  Receive_Timer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Receive_Timer_Sleep(void) 
{
    #if(!Receive_Timer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Receive_Timer_CTRL_ENABLE == (Receive_Timer_CONTROL & Receive_Timer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Receive_Timer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Receive_Timer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Receive_Timer_Stop();
    Receive_Timer_SaveConfig();
}


/*******************************************************************************
* Function Name: Receive_Timer_Wakeup
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
*  Receive_Timer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Receive_Timer_Wakeup(void) 
{
    Receive_Timer_RestoreConfig();
    #if(!Receive_Timer_UDB_CONTROL_REG_REMOVED)
        if(Receive_Timer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Receive_Timer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
