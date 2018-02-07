/*
  @file conversion.c  
  @brief This file is used to convert integers to ASCII and vice versa

  The file consists of two functions: itoa() and atoi().  itoa() takes in an 
  integer value and outputs the ASCII equivalent of that value.  atoi() takes
  in an ASCII value and converts it to an integer.

  @author Stephen Bowern
  @date Jan 30, 2018
*/

#include <stdio.h>
#include <stdint.h>
#include <conversion.h>

/*
  @brief This function converts an integer value to an ASCII value

  This function takes in a 32 bit data intiger, an integer pointer, and a base.
  The function converts the integer data to ASCII with respect to the base, and 
  assigns that ASCII string to the pointer.  The function returns an integer
  representing the number of the ASCII characters assigned, including negative
  sign and null terminator.

  @return uint8_t
*/
uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base)
{
  const uint8_t MAX = 34;   /*max string length: 32 binary values 
                             + negative sign + null terminator*/
  uint32_t udata = data;    /*temp unsigned data value storage*/
  uint8_t temp[MAX];        /*temp array to the modulus of the data*/
  uint8_t *tptr = temp;     /*pointer to temp array*/
  uint8_t *origin;          /*pointer to the origin of the destination address*/
  origin = ptr;
  uint8_t count = 0;        /*counts upa and down an integer array*/
  uint8_t total = 0;        /*counts the total number of ASCII values*/
  
  /*if data is negative, assign "-" to first ASCII value
    and assign the positive value of data into an usigned int
  */
  if(data < 0)
  {
    *ptr = 45;
    ptr++;
    udata = data * -1;
    total++;            /*adds one to total for negative sign*/
  }

  /*while the data is greater than 0, assign the modulus
    to the temporary array, and trucate the LSB of data
  */  
  while((udata / base) > 0)
  { 
    *tptr = udata % base;  /*assign*/
    tptr++;                /*increment*/
    udata /= base;         /*truncate*/
    count++;               /*array size*/
    total ++;              /*adds integer array size to total ASCII values*/
  }
  tptr--;                  /*return temp poniter to last valid data value*/

  /*for each character, assign the ASCII value by
    adding 48 for numbers or by 55 for letters
  */
  while(count > 0)
  {
    if(*tptr < 10)
      *ptr = *tptr + 48;
    else
      *ptr = *tptr + 55;

  count--;
  ptr++;
  tptr--;
  }
  *ptr = '\0';              /*assign NULL to last character*/
  total++;                  /*adds one to total for null character*/

  /*return ptr to its original address*/
  ptr = origin;

  return total;
}

/*
  @brief This function converts an ASCII value to an integer value

  This function takes in an integer pointer (pointing to the ASCII data), an
  integer representing the number of digits being input, and a base.
  The function converts the ASCII data to an integer with respect to the base,
  and then returns that value as a 32 bit signed integer.

  @return uint32_t
*/
int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base)
{
  uint8_t isneg = 0;            /*true if the input value is negative*/
  uint8_t temp[digits];
  uint8_t *ptemp = temp;
  uint8_t realdigits = digits;  /*digits - 1 if the ASCII value is negative*/
  uint8_t *origin;              /*pointer to the origin of the destination
                                  address*/
  origin = ptr;
  int32_t result = 0;           /*integer result returned from the function*/
  uint8_t baseprod = 1;         /*product of base to the exp power*/
  uint8_t exp = 1;              /*exponent value used to convert to decimal*/

  /*check if the number is negative*/
  if(*ptr == 45)
  {
    isneg = 1;    
    ptr++;
    realdigits--;    /*remove the negative sign from the real digits count*/
  }
  realdigits--;      /*remove the null terminator from the real digits count*/
  isneg *= 1;        /*performing arbirary operation to avoid compile warning*/

  /*convert ASCII characters to integer numbers and assign them to an array*/
  while(*ptr != '\0')
  {
    if(*ptr >= 48 && *ptr <= 57)       /*between 0 and 9*/
      *ptemp = *ptr - 48;
    else if(*ptr >= 65 && *ptr <= 70)  /*between A and F*/
      *ptemp = *ptr - 55;
    else if(*ptr >= 97 && *ptr <= 102) /*between a and f*/
      *ptemp = *ptr - 87;
    else
      return 1;                        /*gives some indication of error*/

    ptr++;
    ptemp++;
  }
  ptr = origin; /*return pointer to its origin*/
  ptemp--;      /*return to last valid character*/

  /*calculate the integer value of the parsed array*/
  result = *ptemp;         /*assign least significant digit to result*/
  ptemp--;                 /*decrement array to the next significant value*/
  while(ptemp >= ptr)
  {
    for(uint8_t x = 0 ; x < exp ; x++) /*multiply base by itself*/
      baseprod *= base;                /*'exp' number of times  */

    result += *ptemp * baseprod;       /*result gets result plus data value */
    ptemp--;                           /*times base product                 */
    exp++;                             /*increase exponent for next sig value*/
    baseprod = 1;                      /*reset base product for the next loop*/
  }

  return result;
}
