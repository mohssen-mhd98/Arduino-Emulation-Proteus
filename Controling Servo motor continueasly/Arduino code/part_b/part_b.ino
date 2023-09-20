
#include <Keypad.h>
#include <Servo.h>
const int ROW_NUM = 4; //number of rows
const int COLUMN_NUM = 3; //number of columns
//4*3 keyPad
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte pin_rows[ROW_NUM] = {22, 24, 26, 28}; //which row connected to which pin
byte pin_column[COLUMN_NUM] = {36, 37, 38}; //which column connected to which pin

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

int servoPin = 6;
Servo servo;

void setup(){
   Serial.begin(9600);
  servo.attach(servoPin);
  servo.writeMicroseconds(1499);
}
String input_num;
int value=0;

void loop(){
  char key = keypad.getKey();

  if (key){
  
    Serial.print(key);
    if(key == '#') {
      input_num = ""; // clear input number
      Serial.println("");
    } else if(key == '*') {
      Serial.println("");
      value = input_num.toInt();
      Serial.println(value);
      //constrain(value, 0, 180);
      value = map(value, 0, 180, 700, 2300);
      //value = value - 90;
      //constrain(value, -90, 90);
     servo.writeMicroseconds(value);
      input_num = ""; // clear input number
    } else {
      input_num += key; // append new character to input_num string
    }
  }

}
