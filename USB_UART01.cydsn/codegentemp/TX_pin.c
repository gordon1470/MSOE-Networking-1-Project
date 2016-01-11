/*******************************************************************************
* File Name: TX_pin.c  
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
#include "TX_pin.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 TX_pin__PORT == 15 && ((TX_pin__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: TX_pin_Write
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
void TX_pin_Write(uint8 value) 
{
    uint8 staticBits = (TX_pin_DR & (uint8)(~TX_pin_MASK));
    TX_pin_DR = staticBits | ((uint8)(value << TX_pin_SHIFT) & TX_pin_MASK);
}


/*******************************************************************************
* Function Name: TX_pin_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  TX_pin_DM_STRONG     Strong Drive 
*  TX_pin_DM_OD_HI      Open Drain, Drives High 
*  TX_pin_DM_OD_LO      Open Drain, Drives Low 
*  TX_pin_DM_RES_UP     Resistive Pull Up 
*  TX_pin_DM_RES_DWN    Resistive Pull Down 
*  TX_pin_DM_RES_UPDWN  Resistive Pull Up/Down 
*  TX_pin_DM_DIG_HIZ    High Impedance Digital 
*  TX_pin_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void TX_pin_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(TX_pin_0, mode);
}


/*******************************************************************************
* Function Name: TX_pin_Read
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
*  Macro TX_pin_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 TX_pin_Read(void) 
{
    return (TX_pin_PS & TX_pin_MASK) >> TX_pin_SHIFT;
}


/*******************************************************************************
* Function Name: TX_pin_ReadDataReg
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
uint8 TX_pin_ReadDataReg(void) 
{
    return (TX_pin_DR & TX_pin_MASK) >> TX_pin_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(TX_pin_INTSTAT) 

    /*******************************************************************************
    * Function Name: TX_pin_ClearInterrupt
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
    uint8 TX_pin_ClearInterrupt(void) 
    {
        return (TX_pin_INTSTAT & TX_pin_MASK) >> TX_pin_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
