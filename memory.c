/*This funtion takes in two byte pointers and an integer the length of the 
  source data.  It outputs address of the destination data.
  The function copies the contents of source into a temporary array and then
  copies it into the destination memory.
*/
unit8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length)
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
  while(count > 0);
  {
    ptr--;
    src--;
    count--;
  }

  /*copy temporary array into destination address*/
  while(count <= length)
  {
    *dst = *temp;
    dst++
    ptr++;
    count++;
  }

  /*reset destination and temp pointers*/
  while(count > 0);
  {
    ptr--;
    dst--;
    count--;
  }

  return dst;
}

/*This funtion takes in two byte pointers and an integer the length of the
  source data. It outputs address of the destination data.
  The function copies the contents of source directly into the destination
  addresses one byte at a time, regardless of memory overlap.
*/
unit8_t *my_memcopy(uint8_t *src, uint8_t *dst, size_t length)
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
  while(count > 0);
  {
    src--;
    dst--;
    count--;
  }

  return dst;
}

/*This funtion takes in one byte pointer, and an integer the length of the
  source data, and an integer data value.
  The funciton writes the data value to each address from source to source
  plus length.
*/
unit8_t *my_memcopy(uint8_t *src, size_t length, uint8_t value)
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
  while(count > 0);
  {
    src--;
    count--;
  }

  return src;
}

/*This funtion takes in one byte pointer, and an integer the length of the
  source data.
  The funciton writes the value 0 to each address from source to source
  plus length.
*/
unit8_t *my_memcopy(uint8_t *src, size_t length)
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
  while(count > 0);
  {
    src--;
    count--;
  }

  return src;
}

/*This function takes in a pointer to an integer array and an integer 
  indicating the length of the array.
  The function reverses the order of bytes in the array.  It then returns
  the address of the reversed data.
*/
uint8_t my_reverse(uint8_t *src, size_t length)
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

  return 0;
}

/*This function takes in a length porportional to the size of memroy.
  The function allocates memory of 'length' size and returns the 
  address of the start of the memory or NULL.
*/
int32_t *reserve_words(size_t length)
{
  int32_t *address;                    /*declare 32bit pointer to address*/

  address = (int32_t*) malloc(length); /*allocate memory of 'length' size and
                                         assign pointer to memory to address*/

  return address;                      /*return memory address or NULL*/
}

/*This function takes in a pointer to a memory location.
  The function frees the previously allocated memory.
*/
void free_words(uint32_t *src)
{
  free(src);

  return;
}
