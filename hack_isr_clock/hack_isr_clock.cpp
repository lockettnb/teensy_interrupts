// 
//  2015/06/02 created
//
//

#include <stdio.h>
#include <string.h>
#include "Arduino.h"
#include "HardwareSerial.h"
#include "IntervalTimer.h"

extern int portd[];

// #include <avr/io.h>
// #include <avr/interrupt.h>

#define LEDPIN  13 

#define TRUE 1
#define FALSE 0
#define MAXCMDLINE 16 

#define LED_PIN  13 
#define CLOCK_PIN 4
#define ISR_PIN 3

byte pinTable[] = {2,14,7,8,6,20,21,5};
// void isr_clk(void); 

// *************************************************
void isr_clk2(void)
{
// the real ISR is hacked into pin_teensy.c in the core lib
// this routine is just a dummy function used to in the
// call to attachInterrupt which enables the interrupt
//  
}

// *************************************************
void setup()
{
int i;
  for (i=0; i<8; i++) { pinMode(pinTable[i],INPUT); }

  pinMode(LED_PIN, OUTPUT);
  pinMode(ISR_PIN, OUTPUT);
  pinMode(CLOCK_PIN, INPUT);
  attachInterrupt(CLOCK_PIN, isr_clk2, FALLING);

}


void loop() {
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    digitalWrite(LED_PIN, LOW);
    delay(1500);
}


// *************************************************
int main(void)
{
setup();

while(1) {
    loop();
} // while

} // main








