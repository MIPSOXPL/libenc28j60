#include "enc_init.h"

#include "stdint.h"
#include "stdbool.h"

extern bool spi_send_data(const uint16_t address, const uint8_t* data, int data_length);
extern bool spi_receive_data(const uint16_t address, int data_length, uint8_t* buffer, int buffer_size);

void enc_init_receive_buffer(int receive_buffer_size)
{

}
void enc_init_transmit_buffer(int receive_buffer_size)
{

}
