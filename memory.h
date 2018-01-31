#include <stdio.h>

uint8_t *my_memmove(uint8_t *, uint8_t *, size_t);
uint8_t *my_memcopy(uint8_t *, uint8_t *, size_t);
uint8_t *my_memset(uint8_t *, size_t, uint8_t);
uint8_t *my_memzero(uint8_t *, size_t,);
uint8_t *my_reverse(uint8_t *, size_t,);
int32_t *reserve_words(size_t);
void free_words(uint32_t *);
