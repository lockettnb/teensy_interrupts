// 
//  2015/06/02 created
//
//

#include <stdio.h>
#include <string.h>
#include "Arduino.h"
#include "HardwareSerial.h"
#include "IntervalTimer.h"

#define TRUE 1
#define FALSE 0

#define LED_PIN  13 
#define CLOCK_PIN 4
#define ISR_PIN 3

// *************************************************
FASTRUN void isr_clk(void)
{

  digitalWriteFast(ISR_PIN, HIGH);
    __asm__ __volatile("NOP");
    __asm__ __volatile("NOP");
    __asm__ __volatile("NOP");
    __asm__ __volatile("NOP");
    __asm__ __volatile("NOP");
  digitalWriteFast(ISR_PIN, LOW);

}



// *************************************************
void setup()
{
    pinMode(LED_PIN, OUTPUT);
    pinMode(ISR_PIN, OUTPUT);
    pinMode(CLOCK_PIN, INPUT);

    attachInterrupt(CLOCK_PIN, isr_clk, FALLING);
}



// *************************************************
int main(void)
{

// init();
setup();
while(1) {
    digitalWrite(LED_PIN, HIGH);
    delay(2000);
    digitalWrite(LED_PIN, LOW);
    delay(1000);
} // while
} // main
