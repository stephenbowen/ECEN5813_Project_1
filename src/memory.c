/*
  @file memory.c  
  @brief This file is used to alter data in various memory addresses.

  The file consists of several functions.  my_memmove() moves data from one
  address to another address.  my_memcopy() performs the same function, but does
  not copy the entire dataset before writing to the new address.  my_memset()
  writes a single data value to a number of addresses.  my_memzero() writes a
  value of 0 to a number of addresses.  my_reverse() reverses the data in a set
  of addresses.  *reserve_words() dynamically allocates memory of a given
  length.  free_words() dynamically frees the memory that was previously
  allocated.

  @author Stephen Bowern
  @date Jan 25, 2018
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "memory.h"

/*
  @brief This function copies data to a specified address.

  This function takes in a pointer to a source of data, a pointer to a data
  destination, and the length of the data.  The function copies the data into
  a temporary array and then writes that data to the desination address.  The
  function then returns the address of the destination.

  @return uint8_t *
*/
uint8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length)
{
  uint8_t temp[length];      /*temporary storage of data*/
  uint8_t *ptr = temp;       /*pointer to temp*/
  uint8_t count = 0;         /*counts up and down the temporary data array*/

  /*copy source data into a temporary array*/
  while(count <= length)
  {
    *ptr = *src;
    ptr++;
    src++;
    count++;
  }

  /*reset source and temp pointers*/
  while(count > 0)
  {
    ptr--;
    src--;
    count--;
  }

  /*copy temporary array into destination address*/
  while(count <= length)
  {
    *dst = *temp;
    dst++;
    ptr++;
    count++;
  }

  /*reset destination and temp pointers*/
  while(count > 0)
  {
    ptr--;
    dst--;
    count--;
  }

  return dst;
}

/*
  @brief This function copies data to a specified address.

  This function takes in a pointer to a source of data, a pointer to a data
  destination, and the length of the data.  The function copies the data to the
  destination address one byte at a time, regardless of memory overlap.  The
  function then returns the address of the destination.

  @return uint8_t *
*/
uint8_t *my_memcpy(uint8_t *src, uint8_t *dst, size_t length)
{

  uint8_t count = 0;             /*counts up and down the memory addresses*/

  /*copy source data into destination addresses*/
  while(count <= length)
  {
    *dst = *src;
    src++;
    count++;
  }

  /*reset source and destination pointers*/
  while(count > 0)
  {
    src--;
    dst--;
    count--;
  }

  return dst;
}

/*
  @brief This function sets number of data values to a given value.

  This function takes in a pointer to a source of data, a number of data values
  and the value to be written.  The function writes the given data value to each
  of the address for the given length.  The function then returns the address
  of the source of data.

  @return uint8_t *
*/
uint8_t *my_memset(uint8_t *src, size_t length, uint8_t value)
{

  uint8_t count = 0;             /*counts up and down the memory addresses*/

  /*copy data value into source addresses*/
  while(count <= length)
  {
    *src = value;
    src++;
    count++;
  }

  /*reset source pointer*/
  while(count > 0)
  {
    src--;
    count--;
  }

  return src;
}

/*
  @brief This function set the data value to 0 for a number of addresses.

  This function takes in a pointer to a source of data, and the length of the
  data to be written to.  The function writes 0 to each of these data
  addresses.  The functio then returns the address of the source of data.

  @return uint8_t *
*/
uint8_t *my_memzero(uint8_t *src, size_t length)
{

  uint8_t count = 0;             /*counts up and down the memory addresses*/

  /*write 0 into source addresses*/
  while(count <= length)
  {
    *src = 0;
    src++;
    count++;
  }

  /*reset source pointer*/
  while(count > 0)
  {
    src--;
    count--;
  }

  return src;
}

/*
  @brief This function reverses a set of data bytes.

  This function takes in a pointer to a source of data, and the length of data.
  The funciton copies the data to a temporary array, then writes the array's
  data back to the source in reverse order.  The function then returns the
  address of the source.

  @return uint8_t *
*/
uint8_t *my_reverse(uint8_t *src, size_t length)
{ 
  int count = 0;                 /*counts up and down the array*/
  char temp[length];             /*tempoary storage for coppied array*/
  char *ptr = temp;              /*pointer to temporary array*/

  /*move the temporary pointer to the end of the temporary array*/
  while(count < length)
  {
    ptr++;
    count++;
  }

  /*copy source into temp in reverse order*/
  while(count >= 0)
  {
    *ptr = *src;
    ptr--;
    src++;
    count--;
  }
  count++;

  /*return pointer to last data address*/
  while(count < length)
  {
    ptr++;
    count++;
  }
  
  /*copy temp data back to source*/
  while(count >= 0)
  {
    *src = *ptr;
    ptr--;
    src--;
    count--;
  }

  return src;
}

/*
  @brief This function dynamically allocates memory.

  This function takes in a length of data.  I then dynamically allocates memory
  of that length.  The function returns the address of the allocated memory.

  @return int32_t
*/
int32_t *reserve_words(size_t length)
{
  int32_t *address;                    /*declare 32bit pointer to address*/

  address = (int32_t*) malloc(length); /*allocate memory of 'length' size and
                                         assign pointer to memory to address*/

  return address;                      /*return memory address or NULL*/
}

/*
  @brief This function frees previously allocated memory.

  This function takes in a pointer to a memory location.  It then frees the
  the memory that was previosly dynamically allocated.  The function returns
  nothing.

  @return void
*/
uint8_t free_words(uint32_t *src)
{
  free(src);

  return 0;
}
