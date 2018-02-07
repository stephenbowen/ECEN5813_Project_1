Repository Name: ECEN5813_Project_1
Author: Stephen Bowen
Contact: stbo6102@colorado.edu
Date: February 6, 2018

Description:
This repository contains files used to perform a number of functions.  Functions
in the memory.c file alter data values and allocate memory.  Functions in the
conversion.c file convert integer values to ASCII characters and vice versa.
The Function in debug.c converts a value to hex.  Functions in data.c display
the size of varous data tyes.  Functions in endian.c determine endianness and
swap endianness.  The function in arch_arm32.c returns the endianness of the 
architecture on which the code is run.

Directions:
To set the functions to be tested, change the function call in the main.c file.
The list of functions is contained in project1.c and project1.h.  

To build the project, navigate to the src directory and run one of the following
commands.
make build PLATFORM=HOST
make build PLATFORM=BBB
make build PLATFORM=KL25Z

To delete unneeded files, navigate to the src directory and run the following
command.
make clean

To run the project executable, navigate to the src directory and run the 
following command.
./project1.elf
