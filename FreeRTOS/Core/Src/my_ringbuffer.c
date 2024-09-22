/*
 * my_ringbuffer.c
 *
 *  Created on: Sep 6, 2024
 *      Author: jlue4
 */


#include <my_ringbuffer.h>
#include <string.h>

void my_ringbuffer_init(ring_buffer* self)
{
  self->data_size=self->next_index=self->start_index=0;
}

bool my_ringbuffer_add_byte(ring_buffer* self, uint8_t data)
{
  // TODO: overroll

  if (self->data_size >= RING_BUFFER_LENGTH)
  {
    return false;
  }

  self->buffer[self->next_index++]=data;
  self->data_size++;

  return true;
}

uint16_t my_ringbuffer_read(ring_buffer* self, uint8_t* buffer)
{
  uint16_t size=self->data_size;
  if (size==0)
  {
    return 0;
  }

  memcpy(buffer, &(self->buffer[self->start_index]), self->data_size);

  self->data_size=0;
  self->next_index=0;
  self->start_index=0;

  return size;
}
