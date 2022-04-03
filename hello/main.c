/* Blank template for PICO C program */

/* Minimum include files */
#include <stdio.h>
#include "pico/stdlib.h"

/* Make all DEF's and global declarations here */


/* Function declarations here */

int main() {

    /* Allows USB serial printf */
    stdio_init_all();

    /* Initialization and/or one-time code */
    /* goes here                           */

    /* Every PICO program needs to be a infinite loop, */
    /* at minimum                                      */
    while (true) {

        /* active code goes here  */
        printf("Hello, world!\n");


        /* Some time delay almost always required */
        sleep_ms(1000);
    }

    /* Post operation code goes here */

    /* required, could return a 1 for error */
    return 0;
}

/* Place all function bodies here */