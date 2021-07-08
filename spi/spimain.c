#include "funciones.h"



int main()
 { 
serial_begin();
SPI_init();
sensor_init(1);

   while (1)
     {


_delay_ms(1000);
enviaruart1(1);


}
   return 0;
}
