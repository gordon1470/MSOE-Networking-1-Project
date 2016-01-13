/*******************************************************************************
* File Name: led4.c  
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
#include "led4.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 led4__PORT == 15 && ((led4__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: led4_Write
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
void led4_Write(uint8 value) 
{
    uint8 staticBits = (led4_DR & (uint8)(~led4_MASK));
    led4_DR = staticBits | ((uint8)(value << led4_SHIFT) & led4_MASK);
}


/*******************************************************************************
* Function Name: led4_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  led4_DM_STRONG     Strong Drive 
*  led4_DM_OD_HI      Open Drain, Drives High 
*  led4_DM_OD_LO      Open Drain, Drives Low 
*  led4_DM_RES_UP     Resistive Pull Up 
*  led4_DM_RES_DWN    Resistive Pull Down 
*  led4_DM_RES_UPDWN  Resistive Pull Up/Down 
*  led4_DM_DIG_HIZ    High Impedance Digital 
*  led4_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void led4_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(led4_0, mode);
}


/*******************************************************************************
* Function Name: led4_Read
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
*  Macro led4_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 led4_Read(void) 
{
    return (led4_PS & led4_MASK) >> led4_SHIFT;
}


/*******************************************************************************
* Function Name: led4_ReadDataReg
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
uint8 led4_ReadDataReg(void) 
{
    return (led4_DR & led4_MASK) >> led4_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(led4_INTSTAT) 

    /*******************************************************************************
    * Function Name: led4_ClearInterrupt
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
    uint8 led4_ClearInterrupt(void) 
    {
        return (led4_INTSTAT & led4_MASK) >> led4_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
