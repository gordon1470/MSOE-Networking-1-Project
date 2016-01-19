/*******************************************************************************
* File Name: Receive.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Receive.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Receive__PORT == 15 && ((Receive__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Receive_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void Receive_Write(uint8 value) 
{
    uint8 staticBits = (Receive_DR & (uint8)(~Receive_MASK));
    Receive_DR = staticBits | ((uint8)(value << Receive_SHIFT) & Receive_MASK);
}


/*******************************************************************************
* Function Name: Receive_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Receive_DM_STRONG     Strong Drive 
*  Receive_DM_OD_HI      Open Drain, Drives High 
*  Receive_DM_OD_LO      Open Drain, Drives Low 
*  Receive_DM_RES_UP     Resistive Pull Up 
*  Receive_DM_RES_DWN    Resistive Pull Down 
*  Receive_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Receive_DM_DIG_HIZ    High Impedance Digital 
*  Receive_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Receive_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Receive_0, mode);
}


/*******************************************************************************
* Function Name: Receive_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Receive_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Receive_Read(void) 
{
    return (Receive_PS & Receive_MASK) >> Receive_SHIFT;
}


/*******************************************************************************
* Function Name: Receive_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Receive_ReadDataReg(void) 
{
    return (Receive_DR & Receive_MASK) >> Receive_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Receive_INTSTAT) 

    /*******************************************************************************
    * Function Name: Receive_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Receive_ClearInterrupt(void) 
    {
        return (Receive_INTSTAT & Receive_MASK) >> Receive_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
