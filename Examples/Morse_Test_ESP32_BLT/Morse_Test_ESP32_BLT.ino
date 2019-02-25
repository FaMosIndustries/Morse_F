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

//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial
#define LED LED_BUILTIN
#define ESP32_BT
//#define lSerial
#define lBT
#include <Morse_F.h>

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;


Morse_F Morse(LED,250);//Morse_F(LED-Pin,Unit-in-ms)set Output to pin 13  and a unit duration of 250ms



void setup() {
  digitalWrite(LED,HIGH);
  //Serial.begin(115200);
  //digitalWrite(LED,LOW);
  SerialBT.begin("ESP32SerrialMorse"); //Bluetooth device name
  //digitalWrite(LED,HIGH);
  Serial.println("The device started, now you can pair it with bluetooth!");
  Serial.println("entering Setup");
  Serial.println("dump mors table");
  Morse.dump();
  digitalWrite(LED,LOW);
  Serial.println("leaving Setup");
}

void loop() {
  char c;
    #ifdef lSerial
    if (Serial.available()) {
        while ((c = Serial.read()) > 0) {
            Morse.send(c);
        }
    }
    #endif
    #ifdef lBT
    if (SerialBT.available())
    {
        while ((c = SerialBT.read()) > 0) {
            Morse.send(c);
        }
    }
    #endif
}
