#include "Arduino.h"
#include "Morse_F.h"
//#define debug

char    charact [37];// = {'a' ,'b'    ,'c'    ,'d'    ,'e'    ,'f'    ,'g'    ,'h'    ,'i'    ,'j'    ,'k'    ,'l'    ,'m'    ,'n'    ,'o'    ,'p'    ,'q'    ,'r'    ,'s'    ,'t'    ,'u'    ,'v'    ,'w'    ,'x'    ,'y'    ,'z'    ,'0'     ,'1'     ,'2'     ,'3'     ,'4'     ,'5'     ,'6'     ,'7'     ,'8'     ,'9'     ,' '};
String  MorsCod [37];// = {".-","-..." ,"-.-." ,"-.."  ,"."    , "..-.", "--." , "....", ".."  , ".---", "-.-" , ".-..", "--"  , "-."  , "---" , ".--.", "--.-", ".-." , "..." , "-"   , "..-" , "...-", ".--" , "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."," "};

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
    for (i = 0 ; i < 36 ; i++) {
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
    Serial.print("Char: ");
    Serial.print(c);
    Serial.print("\tm-Code: ");
    Serial.println(MorseCode);
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
    for (d = 0 ; d < 36 ; d++)
    {
        Serial.print(charact[d]);
        Serial.print("=");
        Serial.print(MorsCod[d]);
        Serial.println("/");
    }
}


