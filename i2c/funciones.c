#include "funciones.h"
char rec[10] ;
void lcd_sent(){


	 lcd_cursor(1,5);
	 if(is_data_ready()){
	 lcd_msg(get_RX_buffer());
	 }
}

