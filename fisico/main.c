#include "uart.h"


char* mensaje = "";

int main()
 { 
serial_begin();

while (1)
{
if (is_data_ready()){
mensaje = get_RX_buffer();
serial_println_str(mensaje);
}
serial_println_str("Ecuador virtual Campeón copa América");
_delay_ms(2000);

}
   return 0;
}
