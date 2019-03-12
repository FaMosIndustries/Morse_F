/*
 * Mors Lybary Written By Fabian Morgenthaler alias Dakota
 * 
 * version 1.0 //initial version
 * version 1.1 add some unnecessary but funny ASCII Art
 * version 1.2 expand Morse Table with uppercase chars
 *          .-.__.-.__.-.__.-._.-.
 *        (  How the Hell do I   )
 *         "-"(  draw paws in  )"
 *             "-"(  ASCII?   )
 *                 '-..-"-..-'
 *                        O          _____________________
 *                 ,_    o         _(  Hey, Dad, you got  )_
 *           ____   \"\___,-'7    (   the legs all wrong..  )
 *   ____..-"_.-"|   )     (/      """""""((""""""""""""""""
 *  |   |====    |   a_ /@  E              \\
 *  |FMI|====    | =: T ::= )      __       ))
 *  |## |====    |   \/\   <,     {__\      Y
 *  |___|====____|    7"\_// \       \\  |\__,-7
 *      _/____\_     /( (@)   \      )) _}; .  {
 *     '.,____,.'-.,( \_____ ) \    //   \^ = _/
 *      ._ _        | (((__ ~   ) _//    /&~~")     ,
 *        Y       = |      '-,_    / T-cc_  // }   ((
 *        | __,..--"'          "-,/_ | |  cc7_(     ))
 *                                  "+-,_ |  |"|_,,;/
 *                                       "-, | |--"  -Naughty
 *   surce of above art: http://www.ascii-art.de/ascii/c/cat.txt
 *
 *        
 *              ^      ^
 *            xXXXx   xXXx
 *           XXXXXXx xXXXXx
 *           "XXXXXX XXXXXX ^
 *         ^  XXXXX  XXXXX xXx
 *        XXXx XXXXX  XX" XXXXx
 *        XXXXx "XX"  "  XXXXXX
 *         XXXXX   xXx  XXXXX"
 *          "XX" xXXXXXx "XX"
 *      Jenna  XXXXXXXXXXx
 *           xXXXXXXXXXXXXXx
 *           XXXXXXXXXXXXXXX
 *            """"     """"
*/

#ifndef Morse_F_h
#define Morse_F_h

#include "Arduino.h"

class Morse_F
{
    public:
        //constructor
        Morse_F(byte pin_LED, int Unit_len);

        //Public Funktions
        void send(char c);
        void dump();
        
        //public Variables

    private:
        //Private Funktions
        String get_MorseCode(char c);
        void dot();
        void dash();
        void endLetter();
		void space();
        
        //Private Variables
        byte _pin_LED;
        int _Unit_len;
        //char    charact [63] = {'a'     ,'A'    ,'b'    ,'B'    ,'c'    ,'C'    ,'d'    ,'D'    ,'e'    ,'E'    ,'f'    ,'F'    ,'g'    ,'G'    ,'h'    ,'H'    ,'i'    ,'I'    ,'j'    ,'J'    ,'k'    ,'K'    ,'l'    ,'L'    ,'m'    ,'M'    ,'n'    ,'N'    ,'o'    ,'O'    ,'p'    ,'P'    ,'q'    ,'Q'    ,'r'    ,'R'    ,'s'    ,'S'    ,'t'    ,'T'    ,'u'    ,'U'    ,'v'    ,'V'    ,'w'    ,'W'    ,'x'    ,'X'    ,'y'    ,'Y'    ,'z'    ,'Z'    ,'0'     ,'1'     ,'2'     ,'3'     ,'4'     ,'5'     ,'6'     ,'7'     ,'8'     ,'9'     ,' '};
        //String  MorsCod [63] = {".-"    ,".-"   ,"-..." ,"-..." ,"-.-." ,"-.-." ,"-.."  ,"-.."  ,"."    ,"."    , "..-.", "..-.", "--." , "--." , "....", "....", ".."  , ".."  , ".---", ".---", "-.-" , "-.-" , ".-..", ".-..", "--"  , "--"  , "-."  , "-."  , "---" , "---" , ".--.", ".--.", "--.-", "--.-", ".-." , ".-." , "..." , "..." , "-"   , "-"   , "..-" , "..-" , "...-", "...-", ".--" , ".--" , "-..-", "-..-", "-.--", "-.--", "--..", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."," "};
        char    charact [37] = {'A' ,'B'   ,'C'   ,'D'  ,'E','F'    ,'G'   ,'H'    ,'I'  ,'J'    ,'K'    ,'L'    ,'M'   ,'N'  ,'O'   ,'P'    ,'Q'    ,'R'   ,'S'   ,'T' ,'U'   ,'V'    ,'W'   ,'X'    ,'Y'    ,'Z'    ,'0'     ,'1'     ,'2'     ,'3'     ,'4'     ,'5'     ,'6'     ,'7'     ,'8'     ,'9'     ,' '};
        String  MorsCod [37] = {".-","-...","-.-.","-..",".", "..-.", "--.", "....", "..", ".---", "-.-" , ".-..", "--" , "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."," "};
};
#endif