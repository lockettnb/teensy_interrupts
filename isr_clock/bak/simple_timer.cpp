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

IntervalTimer tm;

// *************************************************
void leddown(void)
{

    digitalWrite(LEDPIN, LOW);
// on clock going low; set address lines and rw line
// on clock going hi ; read data lines 

}



// *************************************************
void setup()
{
    Serial.begin(115200); 
    pinMode(LEDPIN, OUTPUT);

    tm.begin(leddown, 2000);

// read/write and clock lines as output pins
// set read/write to read mode
//     DDRB = DDRB | 0x03 ;        // set PB0 and PB1 as outputs 
//     PORTB = PORTB | 0x02;       // set read/write to read (high)

// set up all data lines for read mode
//   DDRL = 0xff;             // high for outputs for WRITE
//      DDRL = 0x00;             // low for inputs for READ 
    
//  set up all address lines with 0xFFFF
//     DDRA = 0xff;             // address lines A0-A7 high for output 
//     DDRC = 0xff;             // address lines A8-A15 high for output 

// initialize Timer1
//      cli();          // disable global interrupts
//      TCCR1A = 0;     // set entire TCCR1A register to 0
//      TCCR1B = 0;     // same for TCCR1B
 
    // set compare match register to desired timer count:
    // clock = 16MHz; prescale=1024; tick= 1/(16M/1024) = 0.000064 sec = 0.064msec
    // period = 2 * tick * (count +1) = 2 * 0.064 * 8 = 1.024msec 
    // freq = 1/period = 1/1.024msec = 976Hz
//      OCR1A = 7;
//       OCR1A = 8000;

    // turn on CTC mode:
//      TCCR1B |= (1 << WGM12);
    // Set CS10 and CS12 bits for 1024 prescaler:
//      TCCR1B |= (1 << CS10);
//      TCCR1B |= (1 << CS12);
    // enable timer compare interrupt:
//      TIMSK1 |= (1 << OCIE1A);
    // enable global interrupts:
//      sei();

}



// *************************************************
int main(void)
{

// init();
setup();
while(1) {
//     Serial.print("$> ");
    digitalWrite(LEDPIN, HIGH);
    delay(2000);
} // while
} // main
