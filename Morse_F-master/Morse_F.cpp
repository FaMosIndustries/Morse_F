/*
 * Mors Lybary Written By Fabian Morgenthaler alias Dakota
 * 
 * version 1.0 //initial version
 * version 1.2 expand Morse Table with uppercase chars and ass zthis header
 */


#include "Arduino.h"
#include "Morse_F.h"
//#define debug

char    charact [37];
String  MorsCod [37];

Morse_F::Morse_F(byte pin_LED, int Unit_len){
    _pin_LED = pin_LED;
    _Unit_len = Unit_len;
    pinMode(_pin_LED, OUTPUT);
    digitalWrite(_pin_LED,HIGH);
    digitalWrite(_pin_LED,LOW);
    Serial.begin(115200);
}
    

void Morse_F::dot()
{
    #ifdef debug
        Serial.println("dot");
    #endif
    digitalWrite(_pin_LED, HIGH);
    delay(_Unit_len);
    digitalWrite(_pin_LED, LOW);
    delay(_Unit_len);
}

void Morse_F::dash()
{   
    #ifdef debug
        Serial.println("dash");
    #endif
    digitalWrite(_pin_LED, HIGH);
    delay(3 * _Unit_len);
    digitalWrite(_pin_LED, LOW);
    delay(_Unit_len);
}
void Morse_F::endLetter()
{
    #ifdef debug
        Serial.println("let end");
    #endif
	delay(3 * _Unit_len);
}

void Morse_F::space()
{
    #ifdef debug
        Serial.println("space");
    #endif
	delay(7 * _Unit_len);
}

String Morse_F::get_MorseCode(char c)
{
    #ifdef debug
        Serial.println("getMC");
    #endif
    byte i;
    for (i = 0 ; i < sizeof(charact); i++) {
        if (charact[i] == c) {
            #ifdef debug
                Serial.println("found char");
            #endif
            return MorsCod[i];
        }
    }
    // If no matching character, consider it is a space.
    #ifdef debug
        Serial.println("NOT found char");
    #endif
    return " ";
}

void Morse_F::send(char c)
{
    String MorseCode = get_MorseCode(c);
    //Serial.print("Char: ");
    Serial.print(c);
    Serial.print(" ");
    //Serial.print("\tm-Code: ");
    Serial.println(MorseCode);
    /*#ifdef ESP32_BT
        //SerrialBT.Print is not suportet so ... we need to do it 
        String temp = "Char: "+c+"\tm-Code: "+MorseCode;
        // Length (with one extra character for the null terminator)
        int str_len = temp.length() + 1; 
        // Prepare the character array (the buffer) 
        char char_array[str_len];
        // Copy it over 
        str.toCharArray(char_array, str_len);
        for(size_t ind = 0; ind < str_len; ind++)
        {
            SerialBT.write(char_array[i]);
        } 
    #endif*/
    byte i;
    char MorseCodeLength = MorseCode.length();
    for (i = 0 ; i < MorseCodeLength ; i++) { // loop the whole string 
        switch (MorseCode.charAt(i)) {
            case '.':
                dot();
                break;

            case '-':
                dash();
                break;

            case ' ':
                space();
                return;
        }
    }
    endLetter();
}
void Morse_F::dump()
{
    byte d;
    for (d = 0 ; d < sizeof(charact) ; d++)
    {
        Serial.print(charact[d]);
        Serial.print(" ");
        Serial.print(MorsCod[d]);
        Serial.println("");
        /*#ifdef ESP32_BT
            //SerrialBT.Print is not suportet so ... we need to do it 
            String temp = charact[d] + "=" + MorsCod[d] + "/\n";
            // Length (with one extra character for the null terminator)
            int str_len = temp.length() + 1; 
            // Prepare the character array (the buffer) 
            char char_array[str_len];
            // Copy it over 
            str.toCharArray(char_array, str_len);
            for(size_t ind = 0; ind < str_len; ind++)
            {
                SerialBT.write(char_array[i]);
            } 
        #endif*/
    }
}


