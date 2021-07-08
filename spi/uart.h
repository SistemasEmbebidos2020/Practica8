

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "SPI.h"
#include <stdio.h>
#include <stdbool.h>

void serial_begin();
unsigned char serial_read_char();
void serial_print_char(unsigned char caracter);
void serial_print_str(char* cadena);
void conf_int();
void blink();
void serial_println_str(char *cadena);
char* get_RX_buffer();
bool is_data_ready();