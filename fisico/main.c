#include "uart.h"


char* mensaje = "";



int main()
 { 
serial_begin();

   while (1)
     {
mensaje = leer();
serial_println_str("Ecuador virtual Campeón copa América");
_delay_ms(2000);

}
   return 0;
}
