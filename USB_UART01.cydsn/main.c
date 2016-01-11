/*******************************************************************************
* File Name: main.c
*
* Version: 1.0
*
* Description:
*   Enumerates as a Virtual Com port.  Receives data from hyper terminal, then 
*   send received data backward. LCD shows the Line settings.
*   
*  To test project:
*   1. Build the project and program the hex file on to the target device.
*   2. Select 3.3V in SW3 and plug-in power to the CY8CKIT-001
*   3. Connect USB cable from the computer to the CY8CKIT-001.
*   4. Select the USB_UART.inf file from the project directory, as the driver 
*      for this example once Windows asks for it.
*   5. Open "Device Manager" and note the COM port number for "Example Project"
*      device.
*   6. Open "HyperTerminal" application and make new connection to noted COM port
*   7. Type the message, observe echo data received.
*
* Related Document:
*  Universal Serial Bus Specification Revision 2.0 
*  Universal Serial Bus Class Definitions for Communications Devices 
*  Revision 1.2
*
********************************************************************************
* Copyright 2012, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <device.h>
#include "stdio.h"
void atoB(uint8 dec);
int main()
{
    char rx;
    uint8 flag = 0;
    char lineStr[100];
    uint8 position = 0;
    /* Enable Global Interrupts */
    CyGlobalIntEnable;                        

    /* Start USBFS Operation with 3V operation */
    USBUART_1_Start(0u, USBUART_1_3V_OPERATION);
    
    TX_pin_Write(1);
    /* Main Loop: */
    for(;;)
    {
        if(USBUART_1_IsConfigurationChanged() != 0u) /* Host could send double SET_INTERFACE request */
        {
            if(USBUART_1_GetConfiguration() != 0u)   /* Init IN endpoints when device configured */
            {
                /* Enumeration is done, enable OUT endpoint for receive data from Host */
                USBUART_1_CDC_Init();
            }
        }         
        if(USBUART_1_GetConfiguration() != 0u)    /* Service USB CDC when device configured */
        {
            if(USBUART_1_DataIsReady() != 0u)               /* Check for input data from PC */
            {   
                rx = USBUART_1_GetChar();
                switch(rx){
                    case 8://backspace
                    if(position>0){
                        position--;
                        lineStr[position] = '\0';
                        //backspace space backspace
                        while(USBUART_1_CDCIsReady() == 0u); 
                        USBUART_1_PutChar(8);
                        USBUART_1_PutChar(32);
                        USBUART_1_PutChar(8);
                    }
                    break;
                    case 13://enter (carriage return)
                    flag = 1;
                    while(USBUART_1_CDCIsReady() == 0u);
                    USBUART_1_PutCRLF();
                    break;
                    case 27://escape
                    break;
                    default://everything else
                    lineStr[position] = rx;
                    position++;
                    while(USBUART_1_CDCIsReady() == 0u); 
                    USBUART_1_PutChar(rx);       /* Send data back to PC */
                    break;
                }
            }
            if(flag && position != 0){
                int i = 0;
                flag = 0;
                TX_pin_Write(0);
                CyDelayUs(250);//1/4000th of a sec, or 2000 baud with diff man
                TX_pin_Write(1);
                CyDelayUs(250);
                for(i = 0; i < position; i++){
                    atoB(lineStr[i]);
                }
            }else flag = 0;
        }
    }   
}

void atoB(uint8 dec)
    {
	  int a[20];//flag "ten" checks if 1 is represented as "10" or "01",
      int i=0,j,ten = 0;
      while(dec>0) 
      { 
           a[i]=dec%2; 
           i++; 
           dec=dec/2;
      }
      for(j=i-1;j>=0;j--) 
      {
        if(a[j]){//if 1, ten flag is changed
            ten = !ten;   
        }
        if(ten){
            TX_pin_Write(1);
            CyDelayUs(250);//1/4000th of a sec, or 2000 baud with diff man
            TX_pin_Write(0);
            CyDelayUs(250);
        }else{
            TX_pin_Write(0);
            CyDelayUs(250);//1/4000th of a sec, or 2000 baud with diff man
            TX_pin_Write(1);
            CyDelayUs(250);
        }
      }
    TX_pin_Write(1);//set to HIGH at the end
    }

/* [] END OF FILE */
