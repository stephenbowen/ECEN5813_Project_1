#include <stdio.h>
#include <stdint.h>
#include <arch_arm32.h>

uint32_t ARM32_AIRCR_get_endianness_setting()
{
  return ((__AIRCR_ENDIANNESS_MASK) >> __AIRCR_ENDIANNESS_OFFSET);
}
