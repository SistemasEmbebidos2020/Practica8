#include "i2c.h" 
#define F_SCL 100000
#include <math.h>

void i2c_init(){
	//TWBR = 0x48;		//	I frecuencia 9600 is set by calculating    62  frecuency 100khz
	TWSR = 0x00;		//Prescaler set to 1
	uint8_t Presscaler = pow(2,(2*(TWSR & 0b11)));//solo para tomar en cuenta los dos bits menos significativos ya que el resto puede cambiar
	TWBR = ((F_CPU / F_SCL)-16)/(2*Presscaler);//formula de la frecuencia de reloj del i2c que debe ser 100KHz segun el fabricante de los slave
	TWCR = (1<<TWEN);	//Enable I2C
}
		//Start condition
void i2c_start(){
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTA);	//start condition
	while (!(TWCR & (1<<TWINT)));				//check for start condition
}

void i2c_write(char x){				//Con esta funcion se escribe en el bus de TWDR
	TWDR = x;						//Move value to I2C
	TWCR |=  (1<<TWEN);	//Enable I2C e inicio de transmision
	while  (!(TWCR &(1<<TWINT)));
}
		//I2C stop condition
void i2c_stop(){				
	TWCR = (1<<TWINT) | (1<<TWEN)  | (1<<TWSTO);	//stop condition
	while  (TWCR &(1<<TWSTO));					//check for stop condition
}

char i2c_read(){
	TWCR  = (1<<TWEN) | (1<<TWINT);	//Enable I2C and clear interrupt
	while (!(TWCR & (1<<TWINT)));	//Read successful with all data received in TWDR
	return TWDR;
}

