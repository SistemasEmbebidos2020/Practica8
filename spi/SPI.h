#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>


#define SPI_DDR DDRB
#define CS      PINB2
#define MOSI    PINB3
#define MISO    PINB4
#define SCK     PINB5


void sensor_init(int sl);
uint8_t SPI_masterReceive();
void SPI_init();
void SPI_slaveON(uint8_t slave);
void SPI_slaveOFF(uint8_t slave);
void SPI_masterTransmit(uint8_t data);
int16_t readTemp(int sl);