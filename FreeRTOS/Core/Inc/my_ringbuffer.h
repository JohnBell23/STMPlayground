/*
 * my_ringbuffer.h
 *
 *  Created on: Sep 6, 2024
 *      Author: jlue4
 */

#ifndef INC_MY_RINGBUFFER_H_
#define INC_MY_RINGBUFFER_H_

#include <stdint.h>
#include <stdbool.h>

#define RING_BUFFER_LENGTH 255

typedef struct _ring_buffer
{
  uint8_t buffer[RING_BUFFER_LENGTH];
  uint16_t data_size;
  uint16_t start_index;
  uint16_t next_index;
} ring_buffer;


void my_ringbuffer_init(ring_buffer* self);
bool my_ringbuffer_add_byte(ring_buffer* self, uint8_t data);
uint16_t my_ringbuffer_read(ring_buffer* self, uint8_t* buffer);

#endif /* INC_MY_RINGBUFFER_H_ */
