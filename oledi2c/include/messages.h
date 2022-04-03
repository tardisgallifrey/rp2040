#if !defined(REQUIRED_INCLUDES_FOR_MESSAGES)
#define REQUIRED_INCLUDES_FOR_MESSAGES
#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#endif // REQUIRED_INCLUDES_FOR_MESSAGES

char messages[4][100];

void add_msg(char *message);
void display_messages(void);
void messages_init(void);

void add_msg(char *message){
    strcpy(messages[3], messages[2]);
    strcpy(messages[2], messages[1]);
    strcpy(messages[1], messages[0]);
    strcpy(messages[0], message);

}

void display_messages(){
    for(int i = 0; i < 4; i++){
        if(strlen(messages[i]) > 2){
            printf("%s\n", messages[i]);
        }
    }
    sleep_ms(1000);
}

void messages_init(){
    for(int i = 0; i < 4; i++){
        strcpy(messages[i], "  ");
    }
}
