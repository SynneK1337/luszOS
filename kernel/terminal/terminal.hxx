#ifndef _TERMINAL
#define _TERMINAL

#include <stdint.h>
#include <stddef.h>

namespace terminal {
    extern uint8_t color;
    extern size_t column, row;
    extern uint16_t* const buffer;
    void clear();
    void newline(size_t& column = terminal::column, size_t& row = terminal::row);
    void putchar(char c, uint8_t color = terminal::color, size_t x = terminal::column, size_t y = terminal::row);
    void putstr(const char str[], uint8_t color = terminal::color, size_t x = terminal::column, size_t y = terminal::row);
    void scroll(int lines = 1);
}

#endif