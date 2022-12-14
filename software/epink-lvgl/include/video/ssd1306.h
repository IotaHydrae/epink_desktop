/**
 * @file ssd1306.h
 * @author IotaHydrae (writeforever@foxmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-01
 * 
 * MIT License
 * 
 * Copyright 2022 IotaHydrae(writeforever@foxmail.com)
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * 
 */

#pragma once

#ifndef __SSD1306_H
#define __SSD1306_H

#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

#define SSD1306_ADDRESS (0x3c)

#define SSD1306_128_32 1
#define SSD1306_128_64 0

#ifndef OLED_MODULE_TYPE
    #if SSD1306_128_32
        #define OLED_MODULE_TYPE SSD1306_128_32
    #else
        #define OLED_MODULE_TYPE SSD1306_128_64
    #endif
#endif

#if OLED_MODULE_TYPE == SSD1306_128_64
    #define SSD1306_HOR_RES_MAX 128
    #define SSD1306_VER_RES_MAX 64
#elif OLED_MODULE_TYPE == SSD1306_128_32
    #define SSD1306_HOR_RES_MAX 128
    #define SSD1306_VER_RES_MAX 32
#else
    #define SSD1306_HOR_RES_MAX 128
    #define SSD1306_VER_RES_MAX 32
#endif

#define SSD1306_BUFFER_SIZE ((SSD1306_HOR_RES_MAX * SSD1306_VER_RES_MAX)/8)
#define SSD1306_PAGE_SIZE (SSD1306_VER_RES_MAX/8)
#define OLED_COLOR_DEPTH 1

#define OFFSET(p, c) ((p)*128 + (c))
#define GET_PAGE_FROM_BUFFER(i) (i / 128)
#define GET_COL_FROM_BUFFER(i) (i % 128)

#define GET_PAGE(pc) (pc >> 16)
#define GET_COL(pc) (pc & 0xFFFF)
#define PAGE_COL(page, col) ((page << 16) | col)
#define PAGE_COL_GET_X(pc) (GET_COL(pc))
#define PAGE_COL_GET_Y(pc) (GET_PAGE(pc) * 8)

// #define OLED_COORD_CHECK

typedef enum {
    SSD1306_ADDR_MODE_HORIZONTAL,
    SSD1306_ADDR_MODE_VERTICAL,
    SSD1306_ADDR_MODE_PAGE,
    SSD1306_ADDR_MODE_INVALID,
}ssd1306_addr_mode_t;

/**
 * Register Map of SSD1306
 * 0x00 ~ 0xFF
 */

// void ssd1306_init();
// void ssd1306_write_data(uint8_t val);
// void ssd1306_put_pixel(uint8_t x, uint8_t y, uint8_t color);
// void ssd1306_flush();

void ssd1306_test();
void ssd1306_banner();

#endif /* __SSD1306_H */