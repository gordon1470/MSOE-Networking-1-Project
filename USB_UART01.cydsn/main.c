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
#include <stdbool.h>
#include "stdio.h"

#define INDEX_OF_MSB 6
void initDiffManEncodedArray();
void transmitData(char*, uint8);
void asciiToDiffMan(char);

int diffManEncodedData[800];
int halfBitIndex = 0, currentDataPos=0, lengthOfData;
bool timerExpired;

CY_ISR(TimerHandler){
    Timer_STATUS;//clear the timer interrupt
    Timer_Stop();
    timerExpired = true;
    
    /*if(currentDataPos < halfBitIndex){
        TX_pin_Write(diffManEncodedData[currentDataPos]);
        currentDataPos++;
    }*/
}

int main()
{
    char rx;
    char lineString[100];
    uint8 stringPosition = 0;
    timerExpired = false;
    /* Enable Global Interrupts */
    CyGlobalIntEnable;                        
    
    initDiffManEncodedArray();

    /* Start USBFS Operation with 3V operation */
    USBUART_1_Start(0u, USBUART_1_3V_OPERATION);
    TimerISR_StartEx(TimerHandler);
    
    TX_pin_Write(1);
    
    //test
    LCD_Start();
    //end test
    
    
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
                        if(stringPosition>0){
                            stringPosition--;
                            lineString[stringPosition] = '\0';
                            //backspace space backspace
                            while(USBUART_1_CDCIsReady() == 0u); 
                            USBUART_1_PutChar(8);
                            USBUART_1_PutChar(32);
                            USBUART_1_PutChar(8);
                        }
                    break;
                    case 13://enter (carriage return)
                        transmitData(lineString, stringPosition);
                        while(USBUART_1_CDCIsReady() == 0u);
                        USBUART_1_PutCRLF();
                        
                        //trans data
                        int i;
                        int x = 0;
                        for(i = 0;i < halfBitIndex; i++){
                            TX_pin_Write(diffManEncodedData[i]);
                            Timer_Start();
                            while(!timerExpired); 
                            timerExpired = false;
                        }
                        TX_pin_Write(1);
                        //end trans data
                        
                        halfBitIndex = 0;
                        stringPosition = 0;
                        //halfBitIndex = 0;
                        
                    break;
                    case 27://escape
                    break;
                    default://everything else
                        lineString[stringPosition] = rx;
                        stringPosition++;
                        while(USBUART_1_CDCIsReady() == 0u); 
                        USBUART_1_PutChar(rx);       /* Send data back to PC */
                    break;
                }
            }
        }
    }   
}

/*
init dif man encoded data array with a leading "starting bit". The starting bit is madeup of the 
half bits 01.
*/
void initDiffManEncodedArray(){
    halfBitIndex = 0;
    diffManEncodedData[halfBitIndex] = 0;
    halfBitIndex++;
    diffManEncodedData[halfBitIndex] = 1;
    halfBitIndex++;
}

/*
enter key has been pressed, transmit diff man data
*/
void transmitData(char lineString[], uint8 stringPosition){

    unsigned int i = 0;
    for(i = 0; i < stringPosition; i++){
        asciiToDiffMan(lineString[i]);
    }
}

/*
Helper method
Converts a ascii char to a differental manchester line encoded version
*/
void asciiToDiffMan(char asciiChar)
{
    uint8 previousHalfBit = diffManEncodedData[halfBitIndex-1];
    //send starting 1 bit (encoded)
    if(previousHalfBit == 1){
        diffManEncodedData[halfBitIndex] = 1;
        halfBitIndex++;
        diffManEncodedData[halfBitIndex] = 0;
        halfBitIndex++;
    }else{
        diffManEncodedData[halfBitIndex] = 0;
        halfBitIndex++;
        diffManEncodedData[halfBitIndex] = 1;
        halfBitIndex++;
    } 
    previousHalfBit = diffManEncodedData[halfBitIndex-1];

    
    //convert asciil char to binary value (which will be 7 bits)
    unsigned int binaryValueOfChar[20];//index zero is LSB 
    int i;
    for(i=0; asciiChar>0; i++)
    { 
        binaryValueOfChar[i]=asciiChar%2; 
        asciiChar=asciiChar/2;
    }

    //differential encode the 7 bits (from the binary version of the char)
    //must start at the end of the array so to encode the MSB first 
    int j;
    for(j=INDEX_OF_MSB;j>=0;j--) 
    {
        if(binaryValueOfChar[j] == 1)
        {
            //bit == 1
            if(previousHalfBit == 1)
            {
                diffManEncodedData[halfBitIndex] = 1;
                halfBitIndex++;
                diffManEncodedData[halfBitIndex] = 0;
                halfBitIndex++;    
            }
            else
            {
                diffManEncodedData[halfBitIndex] = 0;
                halfBitIndex++;
                diffManEncodedData[halfBitIndex] = 1;
                halfBitIndex++;
            }
            
        }
        else
        {
            //bit == 0
            if(previousHalfBit == 1)
            {
                diffManEncodedData[halfBitIndex] = 0;
                halfBitIndex++;
                diffManEncodedData[halfBitIndex] = 1;
                halfBitIndex++;
            }
            else
            {
                diffManEncodedData[halfBitIndex] = 1;
                halfBitIndex++;
                diffManEncodedData[halfBitIndex] = 0;
                halfBitIndex++;
            }
        }
        
        previousHalfBit = diffManEncodedData[halfBitIndex-1];
    }//end for
   
    //test
   
    /*for(i=0;i<halfBitIndex; i++){
        LCD_PrintNumber(diffManEncodedData[i]);
    }*/
    //end test
   
}//end function

/* [] END OF FILE */
