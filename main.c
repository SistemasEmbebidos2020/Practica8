#include "funciones.h"

int main()
 { 
      serial_begin();
      i2c_init();
      lcd_init();
     lcd_msg("Temperatura es: ");

     while (1)
      {
	 lcd_sent();    

      }
      return 0;
 }