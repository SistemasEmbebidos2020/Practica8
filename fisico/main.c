#include "uart.h"


const char* mensaje ="";

int main()
 { 
serial_begin();

while (1)
{
serial_println_str("Bienvenido a Sistemas Embebidos");
serial_println_str("Ingresa tu nombre seguido de enter");
while (!is_data_ready()){_delay_ms(20);}
mensaje = get_RX_buffer();
serial_print_str("Bienvenido ");
serial_println_str(mensaje);
_delay_ms(250);
}
   return 0;
}
