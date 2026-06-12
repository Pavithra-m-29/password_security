#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,10,2,A0,A1);

const byte ROWS = 4;
const byte COLS = 3;

char keys[ROWS][COLS] = {
 {'1','2','3'},
 {'4','5','6'},
 {'7','8','9'},
 {'*','0','#'}
};

byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String password = "1234";
String input = "";

void setup() {
  lcd.begin(16,2);
  lcd.print("Enter Password");
}

void loop() {
  char key = keypad.getKey();

  if(key) {

    if(key == '*') {
      input = "";
      lcd.clear();
      lcd.print("Cleared");
      delay(1000);
      lcd.clear();
      lcd.print("Enter Password");
    }

    else if(key == '#') {
      lcd.clear();

      if(input == password) {
        lcd.print("UNLOCKED");
      }
      else {
        lcd.print("LOCKED");
      }

      delay(2000);

      input = "";
      lcd.clear();
      lcd.print("Enter Password");
    }

    else {
      input += key;
      lcd.setCursor(input.length()-1,1);
      lcd.print('*');
    }
  }
}