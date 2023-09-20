
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
  lcd.print("Mohsen Mohammadian");
}
const int numRows = 2;
const int numCols = 16;
int i=0;
void loop() {
  for(i=0;i<11;i++){
    lcd.scrollDisplayRight();
    lcd.setCursor(0,1);
    lcd.scrollDisplayRight();
    lcd.print("Hello world");
    delay(500);
  }
  delay(200);
  for(i=0;i<13;i++){
    lcd.scrollDisplayLeft();
    lcd.setCursor(0,2);
    lcd.scrollDisplayLeft();
    lcd.print("Hello world");
    delay(500);
  }
  delay(200);
}
