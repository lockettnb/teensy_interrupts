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
#define ISR_PIN 3
int isr_time;

// *************************************************
void isr_clk(void)
{

//     Serial.printl("interrupt");
    digitalWrite(ISR_PIN, HIGH);
    delay(1000);
    digitalWrite(ISR_PIN, LOW);
// on clock going low; set address lines and rw line
// on clock going hi ; read data lines 

}



// *************************************************
void setup()
{
    Serial.begin(115200); 
    pinMode(LEDPIN, OUTPUT);
    pinMode(ISR_PIN, OUTPUT);

    attachInterrupt(CLOCK_PIN, isr_clk, RISING);

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
    delay(2000);
    digitalWrite(LEDPIN, LOW);
    delay(1000);
} // while
} // main
