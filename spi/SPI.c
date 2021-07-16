#include "SPI.h"

void SPI_init()
{
    // set CS, MOSI and SCK to output
    SPI_DDR |= (1 << CS) | (1 << MOSI) | (1 << SCK) | (1 << PB1) ;
    PORTB  &= ~(1 << 1) & ~(1 << 2);
    // enable SPI, set as master, and clock to /128	, configurar clock en falling 
    SPCR  |= (1 << SPE) | (1 << MSTR) | (1<<CPHA) ;  // | (1 << SPR1) | (1 << SPR0)  ;

}

void sensor_init(int sl){
            SPI_slaveON(sl);
            SPI_masterTransmit(0x80);		//acceder al registro de control
            SPI_masterTransmit(0x00);		//fijar en modo continuo de lectura de temperatura
            SPI_slaveOFF(sl);
	  _delay_ms(150);
}

int8_t readTemp(int sl){
uint8_t rec1;
	 SPI_slaveON(sl);
	 SPI_masterTransmit(0x02);		//acceder al registro de temperatura (entero)
	 rec1 = SPI_masterReceive();
	 SPI_slaveOFF(sl);
	 return rec1;
}


int8_t SPI_masterReceive()
{
    // transmit dummy byte
   SPDR = 0x082;

    // Wait for reception complete
    while(!(SPSR & (1 << SPIF)));

    // return Data Register
    return SPDR;
}

void SPI_masterTransmit(uint8_t data)
{
	/* Cargar dato al registro */
	SPDR = data;
	/* Esperar a que la transmisión se realice */
	while(!(SPSR & (1<<SPIF)));
}



void SPI_slaveOFF(uint8_t slave)
{
	switch (slave)
	{
		case 1:
			PORTB &=~ (1<<PORTB1);
		break;
		case 2:
			PORTB &=~ (1<<PORTB2);
		break;
	}
}

void SPI_slaveON(uint8_t slave)
{
	switch (slave)
	{
		case 1:
			PORTB |= (1<<PORTB1);
		break;
		case 2:
			PORTB |= (1<<PORTB2);
		break;
	}
}


