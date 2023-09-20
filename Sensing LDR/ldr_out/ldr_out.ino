#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.print("9831502");
  lcd.setCursor(0, 1);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  int ldr = analogRead(A0);
  lcd.setCursor(0, 1);
  lcd.print((int)(((double)ldr/1023)*100));
}
