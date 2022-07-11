#include <util/delay.h>
#include <avr/io.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd1(0x27,16,2);


void setup() {
  lcd1.init();
  lcd1.backlight();
  lcd1.setCursor(1,0);
  lcd1.print("hola mundo");
}

void loop() {
  _delay_ms(1500);
}
