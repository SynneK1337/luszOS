#include "terminal.hxx"
#include "../vga/vga.hxx"
#include "../misc/strlen.hxx"

uint8_t terminal::color = vga::get_color(vga::WHITE, vga::BLACK);
size_t terminal::column = 0;
size_t terminal::row = 0;
uint16_t* const terminal::buffer = (uint16_t*) 0xB8000;


void terminal::putchar(char c, uint8_t color, size_t x, size_t y) {
    const size_t offset = vga::MAX_WIDTH * y + x;
    terminal::buffer[offset] = vga::get_char_entry(c, color);
    ++terminal::column;
    if (terminal::column > vga::MAX_WIDTH) {
        terminal::newline();
    }
}

void terminal::clear() {
    auto color = vga::get_color(vga::LIGHT_GREY, vga::BLACK);
    for (size_t offset = 0; offset < vga::MAX_WIDTH * vga::MAX_HEIGHT; ++offset) {
        terminal::buffer[offset] = vga::get_char_entry(' ', color);
    }
}

void terminal::newline() {
    ++terminal::row;
    terminal::column = 0;
}

void terminal::putstr(const char str[], uint8_t color, size_t x, size_t y) {
    auto len = strlen(str);
    for (size_t i = 0; i < len; ++i) {
        terminal::putchar(str[i], color, x, y);
        ++x;
        if (x > vga::MAX_WIDTH) {
            terminal::newline();
        }
    }   
}

void terminal::scroll(int lines) {
    if (lines > 0) {
        for (size_t offset = 0; offset < vga::MAX_WIDTH * (vga::MAX_HEIGHT - 2); ++offset) {
            terminal::buffer[offset] = terminal::buffer[offset + vga::MAX_WIDTH];
        }
        // clear last line
        for (size_t offset = vga::MAX_WIDTH * (vga::MAX_HEIGHT - 1); offset < vga::MAX_WIDTH * vga::MAX_HEIGHT; ++offset) {
            terminal::buffer[offset] = vga::get_char_entry(' ', terminal::color);
        }
    }
    else if (lines < 0) {
        for (size_t offset = vga::MAX_HEIGHT * vga::MAX_WIDTH; offset >= vga::MAX_WIDTH; --offset) {
            terminal::buffer[offset] = terminal::buffer[offset - vga::MAX_WIDTH];
        }
        // clear  first line
        for (size_t offset = 0; offset < vga::MAX_WIDTH; ++offset) {
            terminal::buffer[offset] = vga::get_char_entry(' ', terminal::color);
        }
    }
}