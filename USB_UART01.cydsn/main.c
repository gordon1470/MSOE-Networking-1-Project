#define INDEX_OF_MSB 6
#define HIGH 1
#define EIGHT_BITS 8
#define START_BIT 2
#define ASCII_CHAR_MASK 0x7F
#define TX_SOURCE_ADDRESS 0
#define RX_DESTINATION_ADDRESS 0//these 2 are supposed to be the same
#define VERSION_NUMBER 1
#define HEADER_POS 7


#include <device.h>
#include <stdbool.h>
#include <stdlib.h> //For random number generator
#include <time.h>
#include "stdio.h"


int getRandomNumber();
void initDiffManEncodedArray();
void stringToDiffMan(char*, uint8);
void asciiToDiffMan(char);
void transmitData();
void setNetworkStateOnLEDs();
void diffManToASCII();
void storeChar();
void printChar();
bool headerCheck();

int diffManEncodedData[864];
uint8 diffManReceivedData[108];
char rxChar[108];
int receivedDataIndex, receivedDataCount;
int halfBitIndex = 0, currentDataPos = 0, currentRXCharPosition = 0, lengthOfData, messageLength, headerCRC, TX_DESTINATION_ADDRESS = 0;
bool timerExpired, dataTransmissionComplete, powerOnEdge, headerValid = false;
enum state {idle, busy, collision} networkState;
enum crc {none, header, message, both} crcState;

char receivedChar;

CY_ISR(Idle_Collision_ISR){ 
    networkState = idle; 
    if(Receive_Read() == HIGH){
        networkState = idle;  
    }
    else{
        networkState = collision;
    }
}

CY_ISR(Edge_detect_ISR){
    //Note: on edge detect, will trigger receive timer to start (see TopDesign)
    Idle_Collision_Timer_Start();
	
    //Ignore power on edge 
    if(!powerOnEdge){
        Receive_Timer_Start(); 
        diffManReceivedData[receivedDataCount] = Receive_Read();
        receivedDataCount++;    
    }
    else{
        powerOnEdge = false;
    }
    networkState = busy;
    Receive_ClearInterrupt();
}

CY_ISR(TimerHandler){
    Timer_Stop();
    timerExpired = true;
    Timer_STATUS;   //clear the timer interrupt
}

//TODO changing from reading to just repeting last data
CY_ISR(ReceiveTimerISR){
    diffManReceivedData[receivedDataCount] = diffManReceivedData[receivedDataCount-1];
    //or  diffManReceivedData[receivedDataCount] = Receive_Read();
    receivedDataCount++;
    Receive_Timer_STATUS;   //clear interrupt
}

int main()
{
    char rx;
    char lineString[108];
    uint8 stringPosition = HEADER_POS;//after header
    timerExpired = false;
    dataTransmissionComplete = false;
	
	messageLength = 0;
	
    powerOnEdge = true; //When the system powers up, it creates a rising edge. 
    //We want to ignore this edge on the rising edge.
	
    /*
    Get value from system clock and
    place in seconds variable.
    */
    time_t seconds; 
    time(&seconds);
    /*
    Convert seconds to a unsigned
    integer for seed for random number generator
    */
    srand((unsigned int) seconds);
            
    TX_pin_Write(1);  //set TX line to high to start
    
    /* Enable Global Interrupts */
    CyGlobalIntEnable;  
    
    Receive_ClearInterrupt();//TODO clearing first edge
    
    LCD_Start();
    
    //enable collision detection
    Idle_Collision_IRQ_StartEx(Idle_Collision_ISR);
    Edge_detect_IRQ_StartEx(Edge_detect_ISR);
    Idle_Collision_Timer_Start();

    /* Start USBFS Operation with 3V operation */
    USBUART_1_Start(0u, USBUART_1_3V_OPERATION);
    
    //start transmission timer
    TimerISR_StartEx(TimerHandler);

    ReceiveTimerIRQ_StartEx(ReceiveTimerISR); 
    
    receivedDataCount = 0;
    receivedDataIndex = 0; 
   
    lineString[0] = 0x71;
	lineString[1] = VERSION_NUMBER;
	lineString[2] = TX_SOURCE_ADDRESS;
	lineString[3] = TX_DESTINATION_ADDRESS;
    lineString[4] = 0; 
	lineString[5] = 0;
	lineString[6] = 0x75;
	
    /* Main Loop: */
    for(;;)
    {
        setNetworkStateOnLEDs();
        
        /*Receive*/
        //Precondidtion: must finished receiving data so channel state machine at idle and wait for a char
        if(networkState == idle && receivedDataCount >= 34){//TODO remove hardcode #
            
            //Verify that have received start bit (01). Note: ignore first edge from turning system on
            if(diffManReceivedData[0] == 0 && diffManReceivedData[1] == 1){
                receivedDataIndex = 2; //skip start bit (two half bits)
                while(receivedDataIndex < receivedDataCount-1){     //Note: receivedDataCount-1 b/c gets one extra bit from Receive_Timer expiring 
                    //wait for 8 bits TODO bad comment
                    //char receivedChar;     TODO move to global variable
                    //char *charPtr = &receivedChar;
                    
                    diffManToASCII();
					//program flow: check for header inside diffManToASCII
					//set flag if header start 0x71 is detected (decimal 113 or ASCII 'q')
					//after diffManToASCII completes, check for header flag
					//if valid, enter "header check" method
					//check first 8 bytes of ascii characters according to spec
					//if valid, set valid flag
					//otherwise discard contents
					storeChar();
                    receivedChar = 0;       //Reset the char
                }
				if(headerCheck()){
                    printChar();
                }
               //TODO remove
                /*LCD_Position(0,0);
                int i;
                for(i=0; i<16;i++){
                    LCD_PrintNumber(diffManReceivedData[i]);
                }
                LCD_Position(1,0);
                
                for(i=16; i<32;i++){
                    LCD_PrintNumber(diffManReceivedData[i]);
                }*/
                //end remove
                
                CyDelay(1000);//TODO remove for testing only    
                LCD_ClearDisplay();//TODO remove
                receivedDataCount = 0;  //Reset count
                receivedDataIndex = 0;  //Reset index
                currentRXCharPosition = 0;
            }
            else{
                //Receive data did not start with the start bit
                receivedDataCount = 0;
                receivedDataIndex = 0; 
                currentRXCharPosition = 0;
            }
        }
        else
        {
            //TODO prob remove this else
        }
        /*End Receive*/
        
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
						lineString[4] = stringPosition - 6;
                        stringToDiffMan(lineString, stringPosition);
                        while(USBUART_1_CDCIsReady() == 0u);
                        USBUART_1_PutCRLF();
                        
                        //keep looping until data is transmitted
						
                        while(!dataTransmissionComplete){//header is mostly encoded already, just need to put in message length
							
                            transmitData();
                            setNetworkStateOnLEDs();
                        }
                        dataTransmissionComplete = false;
                        TX_pin_Write(1);    //set line to logic-1 after transmission
                        //reset index
                        halfBitIndex = 0;
                        stringPosition = HEADER_POS; 
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
                TX_pin_Write(1);
                int value = (getRandomNumber()/128.0)*800.0;
               
                //Back-off a random time between 0 and 0.8 seconds
                CyDelay(value);
                break;
            }
        }
        TX_pin_Write(diffManEncodedData[i]);
        Timer_Start();
        while(!timerExpired); 
        timerExpired = false;
    }
    
    //when finished transmitting diff manchester encoded data, set flag 
    if(i == halfBitIndex){
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

/*
Generates a random value from 1 to 128. Used in the random backoff time equation: (N/128)(0.800 seconds)
*/
int getRandomNumber()
{
    const int MIN_N = 1;
    const int MAX_N = 128;
        
    int n;
/*
    Get first and second random numbers.
    */
    n =rand() % (MAX_N - MIN_N + 1) + MIN_N;
    return n;
}

/*
Helper method.
Convert differental manchester line encoded byte to ascii char

charPtr = pointer to char 
*/
void diffManToASCII()
{
    int i;
    for(i = 0; i < EIGHT_BITS; i++){
        uint8 previousHalfBit = diffManReceivedData[receivedDataIndex-1];
        //send starting 1 bit (encoded)
        if(diffManReceivedData[receivedDataIndex] == 1){
            //current half bit is 1
            if(previousHalfBit == 1)
            {
                receivedChar |= (1 << (7 - i));      
            }
            else
            {
                receivedChar |= (0 << (7 - i));    
            }
        }
        else{
            //current half bit is 0
            if(previousHalfBit == 1)
            {
                receivedChar |= (0 << (7 - i));    
            }
            else
            {
                receivedChar |= (1 << (7 - i));    
            }
        } 
        receivedDataIndex += 2;
    }//end for loop
}

//stores char in receive array
void storeChar(){
    if(currentRXCharPosition > HEADER_POS){
	    receivedChar &= ASCII_CHAR_MASK;
    }
	rxChar[currentRXCharPosition] = receivedChar;
	currentRXCharPosition++;
}

//Grabs all chars and prints to LCD
void printChar(){
	int i;//char position after array
    for(i = 7; i < messageLength; i++){//we are assuming messageLength from the header is valid and corresponds to currentRXCharPosition
		LCD_PutChar(rxChar[i]); 
		//TODO: implement USB transmit
    }
}

//checks received header and strips from array if valid
//otherwise, disregard contents
bool headerCheck(){
    //nested if loops are probably the easiest way to check
	if(rxChar[0] == 0x71){
		if(rxChar[3] == 0x00 || rxChar[3] == RX_DESTINATION_ADDRESS){
			//this is as valid as we go (CRC is optional)
			messageLength = rxChar[4];
            LCD_PrintNumber(rxChar[4]); 
			crcState = rxChar[5];
			headerCRC = rxChar[6];
            CyDelay(1000);
			//return true;
		}
	}
	return false;
}

/* [] END OF FILE */
