#include "i2c.h"
#include <avr/io.h>
#include <util/delay.h>

//Yo asigne el pin 0x02 como el En de la LCD
//y el pin 0x01 como el pin RS de la LCD
//Los pines de los datos los más altos del modulo a los de la lcd P4-D4,P5-D5,P6-D6,P7-D7
//R/W va a tierra

//-----Proto-Type-------//
void lcd_init();			//----LCD Initializing Function
//void toggle();				//----Latching function of LCD
void lcd_cmd_hf(char v1);   //----Function to send half byte command to LCD
void lcd_cmd(char v2);		//----Function to send Command to LCD
void lcd_dwr(char v3);		//----Function to send data to LCD
void lcd_msg(char *c);		//----Function to Send String to LCD
void lcd_cursor(char x, char y); // Fila(0-1) y Columna(0-63); para ver las columnas
						    // superiores a 15, se debe usar la función lcd_rig_sh()
//void delay(int ms);			//----Delay function
void lcd_lef_sh();			//----Left Shifting Function
void lcd_rig_sh();			//----Right Shifting Function
//----------------------//
