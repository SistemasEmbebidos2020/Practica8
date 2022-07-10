//#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "ultrasonico.h"

LiquidCrystal_I2C lcd1(0x27,16,2);


void setup() {
  lcd1.init();
  lcd1.backlight();
  lcd1.setCursor(1,0);
  lcd1.print("hola mundo");
  _delay_ms(1500);
}

void loop() {
  lcd1.setCursor(0,0);
  lcd1.print("Distancia en cm:");
  lcd1.setCursor(5,1);
  lcd1.print(ultra());
  _delay_ms(1500);
  lcd1.clear();
}

