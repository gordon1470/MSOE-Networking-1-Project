/*******************************************************************************
This file performs a transmit. No collision is detected. 
*******************************************************************************/

#include <device.h>
#include <stdbool.h>
#include "stdio.h"

void initDiffManEncodedArray();
void stringToDiffMan(char*, uint8);
void asciiToDiffMan(char);
void transmitData();
void setNetworkStateOnLEDs();

#define INDEX_OF_MSB 6
#define HIGH 1

int diffManEncodedData[800];
int halfBitIndex = 0, currentDataPos=0, lengthOfData;
bool timerExpired, dataTransmissionComplete;
enum state {busy, idle, collision} networkState; 

CY_ISR(Idle_Collision_ISR){
    if(Receive_Read() == HIGH){
        networkState = idle;  
    }
    else{
        networkState = collision;
    }
}

CY_ISR(Edge_detect_ISR){
    networkState = busy;
    Idle_Collision_Timer_Start();
    Receive_ClearInterrupt();
}

CY_ISR(TimerHandler){
    Timer_STATUS;   //clear the timer interrupt
    Timer_Stop();
    timerExpired = true;
}

int main()
{
    char rx;
    char lineString[100];
    uint8 stringPosition = 0;
    timerExpired = false;
    dataTransmissionComplete = false;
    /* Enable Global Interrupts */
    CyGlobalIntEnable;                        
    
    Counter_Start();//start counter for random number generation
    
    TX_pin_Write(1);  //set TX line to high to start
    
    //enable collision detection
    Idle_Collision_IRQ_StartEx(Idle_Collision_ISR);
    Edge_detect_IRQ_StartEx(Edge_detect_ISR);
    Idle_Collision_Timer_Start();

    /* Start USBFS Operation with 3V operation */
    USBUART_1_Start(0u, USBUART_1_3V_OPERATION);
    
    //start tranmission timer
    TimerISR_StartEx(TimerHandler);
    
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
                        initDiffManEncodedArray();
                        stringToDiffMan(lineString, stringPosition);
                        while(USBUART_1_CDCIsReady() == 0u);
                        USBUART_1_PutCRLF();
                        
                        //keep looping until data is transmitted
                        while(!dataTransmissionComplete){
                            transmitData();
                            setNetworkStateOnLEDs();
                        }
                        
                        TX_pin_Write(1);    //set line to logic-1 after transmission
                        //reset index
                        halfBitIndex = 0;
                        stringPosition = 0; 
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
Only call when starting to transfer a new string
*/
void initDiffManEncodedArray(){
    halfBitIndex = 0;
    diffManEncodedData[halfBitIndex] = 0;
    halfBitIndex++;
    diffManEncodedData[halfBitIndex] = 1;
    halfBitIndex++;
}

/*
Enter key has been pressed, change binary data into diff man data.
Call from main. Requires main to access diffManEncodedData array
*/
void stringToDiffMan(char lineString[], uint8 stringPosition){

    unsigned int i = 0;
    for(i = 0; i < stringPosition; i++){
        asciiToDiffMan(lineString[i]);
    }
}

/*
Helper method. Do not call from main.
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
   
}//end function

/*
Transmits the diff man encoded data. Must have converted string to diff man before calling this method.
Checks network state before transmitting.
Note: halfBitIndex will be equal to the size of the diffManEncodedData array at this point.
*/
void transmitData(){
    int i;
    for(i = 0; i < halfBitIndex; i++){
        //check for idle, if network is idle, cotinue to transmit data. 
        //Else break out of transmition and wait random time
        if(networkState != idle){
            if(networkState == collision){
                CyDelay((Counter_ReadCounter()/128)*800);
            }
            break;
        }
        /*
        Notes:
        Need to check if we are in collide specifically and wait for a random time if we are at some point
        We could probably do this inside the if loop above
        For the random wait value, there isn't any easy way to generate random numbers in PSoC
        We could use a rapidly running continuous counter between 0 and 128 and grab the counter value when we need a number
        this would probably be as random as we need
        Our equation would be (from the spec)
        ([Random input from counter]/128)*(800 ms)
        So our random delay time statement would be something like
        CyDelay(([Counter Read Input]/128)*(800));
        This would delay for a random value between 0 & 800 ms, which is what we want
        */
        TX_pin_Write(diffManEncodedData[i]);
        Timer_Start();
        while(!timerExpired); 
        timerExpired = false;
    }
    
    //when finished transmitting diff manchester encoded data, set flag 
    if(i == halfBitIndex - 1){//i should be halfBitIndex - 1 at end of loop
        dataTransmissionComplete = true;
    }
}

void setNetworkStateOnLEDs(){
	 switch(networkState){
        case busy:
        {
            LED4_Write(1);
            LED3_Write(0);
            LED2_Write(0);
            break;
        }
        case idle:
        {
            LED3_Write(1);
            LED4_Write(0);
            LED2_Write(0);
            break;
        }
        case collision:
        {
            LED2_Write(1);
            LED4_Write(0);
            LED3_Write(0);
            break;
        }
        default:
        {
           //error
            break;
        } 
	}
}
/* [] END OF FILE */
