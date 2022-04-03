/* Blank template for PICO C program */

/* Minimum include files */
#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "messages.h"

/* Make all DEF's and global declarations here */


/* Function declarations here */

int main() {

    /* Allows USB serial printf */
    stdio_init_all();

    /* Initialization and/or one-time code */
    /* goes here                           */
    messages_init();

    /* Every PICO program needs to be a infinite loop, */
    /* at minimum                                      */
    while (true) {

        /* active code goes here  */
        add_msg("Hello World.");


        display_messages();
        /* Some time delay almost always required */
        sleep_ms(1000);
    }

    /* Post operation code goes here */
    free(messages);

    /* required, could return a 1 for error */
    return 0;
}

/* Place all function bodies here */
