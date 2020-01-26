#ifndef _VGA
#define _VGA

#include <stdint.h>
#include <stddef.h>

namespace vga {
    constexpr size_t MAX_WIDTH = 80;
    constexpr size_t MAX_HEIGHT = 25;
    enum COLORS {
        BLACK = 0,
        BLUE = 1,
        GREEN = 2,
        CYAN = 3,
        RED = 4,
        MAGENTA = 5,
        BROWN = 6,
        LIGHT_GREY = 7,
        DARK_GREY = 8,
        LIGHT_BLUE = 9,
        LIGHT_GREEN = 10,
        LIGHT_CYAN = 11,
        LIGHT_RED = 12,
        LIGHT_MAGENTA = 13,
        LIGHT_BROWN = 14,
        WHITE = 15,
    };

    uint8_t get_color(enum vga::COLORS fg, enum vga::COLORS bg);
    uint16_t get_char_entry(unsigned char c, uint8_t color);
}

#endif