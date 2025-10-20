/**********************************************************************
  Filename    : ADC formatted for Screen
  Description : Displays A/D value and equivalent voltage
  Author      : David Elmo Ross
  Modification: 2025/01/12
**********************************************************************/
#include "arduino.h"                        // include Arduino.h library

#define PIN_ANALOG_IN 34                    // Pin 34 is the A/D being used
                                            // a2d pins are 34-39

#define LED1 27  
#define LED2 26
#define LED3 25 
void setup() 
{
  Serial.begin(115200);                     // platformio.ini has monitor_speed = 115200                                            // make sure both are set to same value
 pinMode(LED1, OUTPUT);  
 pinMode(LED2, OUTPUT);
 pinMode(LED3, OUTPUT); 
 digitalWrite(LED1,1);
 digitalWrite(LED2,1);
 digitalWrite(LED3,1);
}

void loop() 
{ 
  short adcVal;                             // declare adcVal as a short
  double voltage;                           // declare voltage as a double
                                            // clear screen & start title at (10,30) in red
  printf("\e[1;1H\e[2J\e[10;30H\e[1;31mAnalog Value Analog Voltage");
  printf("\e[0m\e[34m");                    // set data colour to by cyan
  for(;;)                                   // endless loop
  {
      adcVal = analogRead(PIN_ANALOG_IN);   // adcVal gets value from 0-4095
      voltage = adcVal / 4096.0 * 3.333;    // voltages gets value from 0-3.33
      printf("\e[11;35H");                  // position cursor at (11,35)
      printf("%d\t\t%4.2f",adcVal,voltage); // print adcVal and voltage there
      fflush(stdout);                       // fflush stdout to synch screen data
      if(voltage < 1.00)
      {
        digitalWrite(LED1,0);
        digitalWrite(LED2,1);
        digitalWrite(LED3,1);
      }
      else
      if(voltage < 2.00)
      {
        digitalWrite(LED1,1);
        digitalWrite(LED2,0);
        digitalWrite(LED3,1);
      }
      else
      {
        digitalWrite(LED1,1);
        digitalWrite(LED2,1);
        digitalWrite(LED3,0);
      }
      delay(200);                           // wait 200 ms between samples
  }
}
