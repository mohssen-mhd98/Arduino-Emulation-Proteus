

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("Mohsen");
  delay(500);
  for(int i=0;i<16;i++){
    lcd.scrollDisplayRight();
    delay(500);
  }
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Mohsen");
  delay(500);
  for(int i=0;i<16;i++){
    lcd.scrollDisplayRight();
    delay(500);
  }
  lcd.clear();
}
