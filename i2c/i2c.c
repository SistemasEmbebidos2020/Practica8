#include "i2c.h" 

void i2c_init(){
	TWBR = 0x48;		//	I frecuencia 9600 is set by calculating    62  frecuency 100khz
	TWCR = (1<<TWEN);	//Enable I2C
	TWSR = 0x00;		//Prescaler set to 1
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

