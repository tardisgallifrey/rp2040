/**
 * Copyright (c) 2021 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"
#include "oledi2c.h"
#include "raspberry26x32.h"





int main() {
    stdio_init_all();

    //added an i2c initialize function to the header.  
    //TODO do it better to allow IC0 or IC1
    i2c_initialize();

    // run through the complete initialization process
    oled_init();

    // initialize render area for entire frame (128 pixels by 4 pages)
    //This is not typical struct initialization.
    //This is bit field setting for each value.
    //It establishes how many bits are needed for each member
    //Since start_col and start_page are both zero always,
    //Saying that we need 0 bits for them auto sets them at 0.
    //end_col will be set to 127 bits
    //end_page will be set to 7 bits
    struct render_area frame_area = {start_col : 0, 
                                        end_col : OLED_WIDTH - 1,
                                        start_page : 0,
                                        end_page : OLED_NUM_PAGES - 1
                                        };

    //This function takes our frame area and calculates the buffer length                                   
    calc_render_area_buflen(&frame_area);

    // zero the entire display
    //
    //Now we use our frame area to set all 0's in
    //each bit and then render it to the device buffer
    uint8_t buf[OLED_BUF_LEN];
    fill(buf, 0x00);
    render(buf, &frame_area);

    // intro sequence: flash the screen 3 times
    for (int i = 0; i < 3; i++) {
        oled_send_cmd(OLED_IGNORE_RAM); // ignore RAM, all pixels on
        sleep_ms(500);
        oled_send_cmd(OLED_SET_ENTIRE_ON); // go back to following RAM
        sleep_ms(500);
    }

    //This is not demo code
    //Produced four horizontal lines
    uint8_t buf2[OLED_BUF_LEN];
    fill(buf2, 0x04);
    render(buf2, &frame_area);
    sleep_ms(100);
    

    // render 3 cute little raspberries
    struct render_area area = {start_col: 0, end_col : IMG_WIDTH - 1, start_page : 0, end_page : OLED_NUM_PAGES - 1};

    calc_render_area_buflen(&area);

    render(raspberry26x32, &area);

    for (int i = 1; i < 3; i++) {
        uint8_t offset = 5 + IMG_WIDTH; // 5px padding
        area.start_col += offset;
        area.end_col += offset;
        render(raspberry26x32, &area);
    }

    // configure horizontal scrolling
    oled_send_cmd(OLED_SET_HORIZ_SCROLL | 0x00);
    oled_send_cmd(0x00); // dummy byte
    oled_send_cmd(0x00); // start page 0
    oled_send_cmd(0x00); // time interval
    oled_send_cmd(0x03); // end page 3
    oled_send_cmd(0x00); // dummy byte
    oled_send_cmd(OLED_READ_MODE); // dummy byte

    // let's goooo!
    oled_send_cmd(OLED_SET_SCROLL | 0x01);

//#endif

    while(true){
        printf("Hello, OLED display! Look at my raspberries..\n");
        sleep_ms(2000);
    }
    return 0;
}