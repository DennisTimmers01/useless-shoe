#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  lcd.print("testing ma dawg");
  delay(1000);
  lcd.clear();
  lcd.print("this shit works bruv");
  delay(1000);
  lcd.clear();
}
