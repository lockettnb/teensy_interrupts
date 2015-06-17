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
#define LEDPIN  13 

#define TRUE 1
#define FALSE 0
#define MAXCMDLINE 16 

// IntervalTimer tm;
#define CLOCK_PIN 2
int isr_time;

// *************************************************
void isr_clk(void)
{

    Serial.println("interrupt");
    digitalWrite(LEDPIN, LOW);
// on clock going low; set address lines and rw line
// on clock going hi ; read data lines 

}



// *************************************************
void setup()
{
    Serial.begin(115200); 
    pinMode(LEDPIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);
    Serial.println("Starting");

    attachInterrupt(CLOCK_PIN, isr_clk, FALLING);
    sei();

}



// *************************************************
int main(void)
{

// init();
setup();
while(1) {
//     Serial.print("$> ");
    Serial.println("looping");
    digitalWrite(LEDPIN, HIGH);
    delay(4000);
    digitalWrite(LEDPIN, LOW);
    delay(1000);
} // while
} // main
