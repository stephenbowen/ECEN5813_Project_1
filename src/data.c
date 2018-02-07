/*
  @file data.c  
  @brief This file is used to display data type sizes

  The file consists of three functions.  Each funtion displays the data type
  size (in number of bytes) of a number of types.

  @author Stephen Bowern
  @date Feb 1, 2018
*/

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include "data.h"
#include "platform.h"

/*
  @brief Fucntion to display data type sizes

  This function does not take in any values or return any value.
  The function prints the size of each of the C standard types.

  @return void
*/
void print_cstd_type_sizes()
{
  size_t temp;

  temp = sizeof(char);
  PRINTF("char", temp);

  temp = sizeof(short);
  PRINTF("short", temp);

  temp = sizeof(int);
  PRINTF("int", temp);

  temp = sizeof(long);
  PRINTF("long", temp);

  temp = sizeof(double);
  PRINTF("double", temp);

  temp = sizeof(float);
  PRINTF("float", temp);

  temp = sizeof(unsigned char);
  PRINTF("unsigned char", temp);

  temp = sizeof(unsigned int);
  PRINTF("unsigned int", temp);

  temp = sizeof(unsigned long);
  PRINTF("unsigned long", temp);

  temp = sizeof(signed char);
  PRINTF("signed char", temp);

  temp = sizeof(signed int);
  PRINTF("signed int", temp);

  temp = sizeof(signed long);
  PRINTF("signed long", temp);
}

/*
  @brief Fucntion to display data type sizes

  This function does not take in any values or return any value.
  The function prints the size of each of the standard integer types.

  @return void
*/
void print_stdint_type_sizes()
{
  size_t temp;

  temp = sizeof(int8_t);
  PRINTF("int8_t", temp);

  temp = sizeof(uint8_t);
  PRINTF("uint8_t", temp);

  temp = sizeof(int16_t);
  PRINTF("int16_t", temp);

  temp = sizeof(uint16_t);
  PRINTF("uint16_t", temp);

  temp = sizeof(int32_t);
  PRINTF("int32_t", temp);

  temp = sizeof(uint32_t);
  PRINTF("uint32_t", temp);

  temp = sizeof(uint_fast8_t);
  PRINTF("uint_fast8_t", temp);

  temp = sizeof(uint_fast16_t);
  PRINTF("uint_fast16_t", temp);

  temp = sizeof(uint_fast32_t);
  PRINTF("uint_fast32_t", temp);

  temp = sizeof(uint_least8_t);
  PRINTF("uint_least8_t", temp);

  temp = sizeof(uint_least16_t);
  PRINTF("uint_least16_t", temp);

  temp = sizeof(uint_least32_t);
  PRINTF("uint_least32_t", temp);

  temp = sizeof(size_t);
  PRINTF("size_t", temp);

  temp = sizeof(ptrdiff_t);
  PRINTF("ptrdiff_t", temp);
}

/*
  @brief Fucntion to display data type sizes

  This function does not take in any values or return any value.
  The function prints the size of each of the pointer types.

  @return void
*/
void print_pointer_sizes()
{
  size_t temp;

  temp = sizeof(char *);
  PRINTF("char *", temp);

  temp = sizeof(short *);
  PRINTF("short *", temp);

  temp = sizeof(int *);
  PRINTF("int *", temp);

  temp = sizeof(long *);
  PRINTF("long *", temp);

  temp = sizeof(double *);
  PRINTF("double *", temp);

  temp = sizeof(float *);
  PRINTF("float *", temp);

  temp = sizeof(void *);
  PRINTF("void *", temp);

  temp = sizeof(int8_t *);
  PRINTF("int8_t *", temp);

  temp = sizeof(int16_t *);
  PRINTF("int16_t *", temp);

  temp = sizeof(int32_t *);
  PRINTF("int32_t *", temp);

  temp = sizeof(char **);
  PRINTF("char **", temp);

  temp = sizeof(int **);
  PRINTF("int **", temp);

  temp = sizeof(void **);
  PRINTF("void **", temp);

  temp = sizeof(ptrdiff_t);
  PRINTF("ptrdiff_t", temp);
}
