#include "uart.h"


char* mensaje = "";

int main()
 { 
serial_begin();

while (1)
{
serial_println_str("Bienvenido a Sistemas Embebidos");
while (!is_data_ready()){_delay_ms(2);}
mensaje = get_RX_buffer();
serial_println_str(mensaje);
}
   return 0;
}
