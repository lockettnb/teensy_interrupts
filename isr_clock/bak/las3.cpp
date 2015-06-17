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

    digitalWriteFast(ISR_PIN, LOW);

}



// *************************************************
void setup()
{
byte portd_table[] = {2,14,7,8,6,20,21,5};
int i;

    pinMode(LED_PIN, OUTPUT);
    pinMode(ISR_PIN, OUTPUT);
    pinMode(CLOCK_PIN, INPUT);

    // set all Port D pins as inputs
    for(i=0; i<=7; i++) {
        pinMode(portd_table[i], INPUT);
    }
//     attachInterrupt(CLOCK_PIN, isr_clk, FALLING);

    Serial.begin(115200); 
}

//   cpu_bits  =  GPIOD_PDIR & 0x00FF;
//   cpu_bits |= (GPIOC_PDIR & 0x0FFF) << 8;
//   cpu_bits |= (GPIOB_PDIR & 0x00FF) << 20;

// *************************************************
int main(void)
{
int i = 0;
uint32_t bits[1024];
// uint32_t port_bits;
setup();

while(1) {
    digitalWrite(LED_PIN, HIGH);

    for(i=0; i<=1023; i++){
       digitalWriteFast(ISR_PIN, HIGH);
       bits[i] = GPIOD_PDIR & 0x00FF;
       digitalWriteFast(ISR_PIN, LOW);
    }

    for(i=0; i<=128; i++){
        Serial.print(bits[i], HEX);
        Serial.print("  ");
    }
        Serial.println();

    digitalWrite(LED_PIN, LOW);
    delay(4000);

} // while
} // main
