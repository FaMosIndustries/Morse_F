/*
 * More advanced example to send data from serial 
 * 
 * Written By Dakota, alias Fabian Morgenthaler
 * 
 * (c) by FaMo'sIndustries
 * all rigths reserved
 *
 * written at 21.02.2019 by Dakota
 * v1.0
 *  
 * 
 */
#include <Morse_F.h>
#define LED 13
Morse_F Morse(LED,250);//Morse_F(LED-Pin,Unit-in-ms)set Output to pin 13  and a unit duration of 250ms

void setup()
{
    Serial.begin(115200);
    Serial.println("entering Setup");
    digitalWrite(LED,HIGH);
    Serial.println("dump mors table");
    Morse.dump();
    Serial.println("Serial link established!");
    digitalWrite(LED,LOW);
    Serial.println("leaving Setup");
}

void loop()
{
    // If no serial link is available, no need to go further.
    if (Serial.available() == -1) {
        return;
    }

    char c;
    while ((c = Serial.read()) > 0) {
        Morse.send(c);
    }
}