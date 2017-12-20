/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
*/
#include <Keypad.h>
#include <Password.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the symbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};


byte rowPins[ROWS] = {13, 12, 11, 10}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

Password password = Password("2580");

void keySetup(){
  Serial.begin(9600);
}
  
bool keyStatus(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    switch (customKey){

      case '#':
        Serial.println("password reset");
        password.reset();
        return false;
        break;
        
      case '*':
        Serial.println("checking password");

        if (password.evaluate()){
          Serial.println("Success");
          doorOpen();
          return true;
        }else{
          Serial.println("Wrong");
          return false;
        }
        
        break;
        
      default:
        password.append(customKey);
        Serial.println(customKey);
        
    }
  }
}
