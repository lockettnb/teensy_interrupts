// 
//  2015/06/02 created
//
//

#include <stdio.h>
#include <string.h>
#include "Arduino.h"
#include "HardwareSerial.h"
#include "IntervalTimer.h"

// #include <avr/io.h>
// #include <avr/interrupt.h>

#define debug(m) Serial.println(m) 

#define TRUE 1
#define FALSE 0
#define MAXCMDLINE 16 

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

    __asm__ __volatile("NOP");
    __asm__ __volatile("NOP");
    __asm__ __volatile("NOP");
    __asm__ __volatile("NOP");
    __asm__ __volatile("NOP");

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

    Serial.begin(115200); 
}



// *************************************************
int main(void)
{

// init();
setup();
while(1) {
//     Serial.print("$> ");
    Serial.println("looping");
    digitalWrite(LED_PIN, HIGH);
    delay(2000);
    digitalWrite(LED_PIN, LOW);
    delay(1000);
} // while
} // main
