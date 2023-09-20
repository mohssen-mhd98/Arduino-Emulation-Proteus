/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-keypad
 */

#include <Keypad.h>
# include <LiquidCrystal.h>;
const int rs=13, en=12, d4=11, d5=10, d6=9, d7=8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 3; //three columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte pin_rows[ROW_NUM] = {22, 24, 26, 28}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {36, 37, 38}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

const String password = "1234"; // change your password here
String input_password;

void setup(){
  lcd.begin(16,2);
  input_password.reserve(32); 
}

void loop(){
  char key = keypad.getKey();

  if (key){

    if(key == '#') {
      input_password = ""; // clear input password
      lcd.clear();
    } else if(key == '*') {
      lcd.setCursor(0, 2);
      if(password == input_password) {
        lcd.print("correct");     
      } else {
        lcd.print("incorrect");
      }

      input_password = ""; // clear input password
    } else {
      lcd.print(key);
      input_password += key; // append new character to input password string
    }
  }
}
