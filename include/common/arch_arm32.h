#include <stdio.h>
#include <stdint.h>

#define __SCB_ADDRESS             (0xE000E000)
#define __AIRCR_ADDRESS_OFFSET    (0x00000D0C)
#define __AIRCR                   (0xE000ED0C)
#define __AIRCR_ENDIANNESS_OFFSET (15)
#define __AIRCR_ENDIANNESS_MASK   (0b0000_0000_0000_0000_1000_0000_0000_0000)

uint32_t ARM32_AIRCR_get_endianness_setting();
