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

#define ISR_PIN 12
#define IRQ_PIN 11
#define TRIGGER_PIN 10

// *************************************************
// FASTRUN void isr_clk(void)
void isr_clk(void)
{
//   digitalWriteFast(ISR_PIN, HIGH);
//   digitalWriteFast(TRIGGER_PIN, LOW);
//     __asm__ __volatile("NOP");
//     __asm__ __volatile("NOP");
//     __asm__ __volatile("NOP");
//     __asm__ __volatile("NOP");
//     __asm__ __volatile("NOP");
//   digitalWriteFast(ISR_PIN, LOW);
}



// *************************************************
void setup()
{
    pinMode(LED_PIN, OUTPUT);
    pinMode(ISR_PIN, OUTPUT);
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(IRQ_PIN, INPUT);

    digitalWrite(TRIGGER_PIN, LOW);
    attachInterrupt(IRQ_PIN, isr_clk, RISING);
}



// *************************************************
int main(void)
{

// init();
setup();
while(1) {
    digitalWriteFast(TRIGGER_PIN, HIGH);
} // while
} // main
