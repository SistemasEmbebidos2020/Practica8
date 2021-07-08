#include <avr/io.h>

void i2c_init();		//Start condition
void i2c_start();
void i2c_write(char x);
void i2c_stop();	//Stop condition