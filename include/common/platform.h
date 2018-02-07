/*
  @file platform.h
  @brief This file is a header file for data.c

  The file defines a print statement only for the Beagle Bone and HOST systems.

  @author Stephen Bowern
  @date Feb 1, 2018
*/

#include <stdio.h>

/*define a print statement if the specified platform is 
  a host machine or the Beagle Bone Black board.
*/
#ifdef HOST
  #define PRINTF(a, b) \
    printf("size of %s = %d\n", a, b);
#endif

#ifdef BBB
  #define PRINTF(a, b) \
    printf("size of %s = %d\n", a, b);
#endif
