#include <LiquidCrystal_I2C.h>

extern volatile unsigned long timer0_overflow_count;
int pushButton = 4;
int counter = 0;

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
}

void loop() {
  int buttonState = digitalRead(pushButton);
  lcd.print(buttonState);

  if (buttonState) {
    displayNegativeMsg();
    resetCurrentTime();
  } else {
    displayPositiveMsg();
    delay(5000);
    displayCurrentTime();
    delay(3000);
  }
  delay(1000);
}

void resetCurrentTime () {
  timer0_overflow_count = 0;
}

void displayNegativeMsg () {
  lcd.clear();
  lcd.print("Stop met lopen ?");
}

void displayPositiveMsg () {
  lcd.clear();
  lcd.print("Lekker pik "); 
}

void displayCurrentTime () {
  lcd.clear();
  lcd.print(( timer0_overflow_count)/60000);
  lcd.print(" minuten still gezeten");
}

