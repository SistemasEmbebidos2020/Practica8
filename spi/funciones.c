#include "funciones.h"

void enviaruart1(int sl){
char rec1[20] ;
	sprintf(rec1,"%d",readTemp(sl));
	 serial_print_str(rec1);
	 serial_println_str(" C       ");
	_delay_ms(100);
}
/*
void enviaruart2(){
char rec2[10] ;
	sprintf(rec2,"%d",readTemp(2));
	 serial_print_str(rec2);
	 serial_println_str(" C");
	_delay_ms(100);
}
*/