
#include <Keypad.h>
#include   <LiquidCrystal.h>

const int rs=13, en=12, d4=11, d5=10, d6=9, d7=8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const byte ROWS = 4;
const byte COLS = 4;

char keys [ROWS] [COLS] = {
  {'7', '8', '9', '/'},
  {'4', '5', '6', '*'},
  {'1', '2', '3', '-'},
  {'C', '0', '=', '+'}
};
byte rowPins[ROWS] = {22,23,24,25};
byte colPins[COLS] = {30,31,32,33};

Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

boolean presentValue = false;
boolean final = false;
String num1, num2;
int answer;
char op;

void setup()
{
  lcd.begin(16,2);
}

void loop(){

  char key = myKeypad.getKey();

  if(key != NO_KEY && key=='C'){
    lcd.clear();
    final = false;
    presentValue = false;
    if(num1!="")
      num1="";
    if(num2="")
      num2="";
  }
  if (key != NO_KEY && (key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'||key=='0'))
  {
    if (presentValue != true)
    {
      num1 = num1 + key;
      //lcd.setCursor(0, 0); //to adjust one whitespace for operator
      lcd.print(key);
    }
    else 
    {
      num2 = num2 + key;
      //lcd.setCursor(1, 0);
      lcd.print(key);
      final = true;
    }
  }

  else if (presentValue == false && key != NO_KEY && (key == '/' || key == '*' || key == '-' || key == '+'))
  {
    if (presentValue == false)
    {
      presentValue = true;
      op = key;
      //lcd.setCursor(0,1);
      lcd.print(op);
    }
  }

  else if (final == true && key != NO_KEY && key == '='){
    if (op == '+'){
      answer = num1.toInt() + num2.toInt();
    }
    else if (op == '-'){
      answer = num1.toInt() - num2.toInt();
    }
    else if (op == '*'){
      answer = num1.toInt() * num2.toInt();
    }
    else if (op == '/'){
      answer = num1.toInt() / num2.toInt();
    }    
      lcd.print(key);
      num1=answer;
      num2="";
      final = false;
      presentValue = false;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(answer);
  }

}
