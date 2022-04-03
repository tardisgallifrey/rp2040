/* Blank template for PICO C program */

/* Minimum include files */
#include <iostream>
#include "pico/stdlib.h"

/* Make all DEF's and global declarations here */
using namespace std;

class Hello{
    public:
        void write(void){
            cout << "Hello World!" << endl;
        }
};

/* Function declarations here */

int main() {

    /* Allows USB serial printf */
    stdio_init_all();

    /* Initialization and/or one-time code */
    /* goes here */
    Hello myhello;

    /* Every PICO program needs to be a infinite loop, */
    /* at minimum                                      */
    while (true) {

        /* active code goes here  */
        myhello.write();
        /* Some time delay almost always required */
        sleep_ms(1000);
    }

    /* Post operation code goes here */
    

    /* required, could return a 1 for error */
    return 0;
}

/* Place all function bodies here */
