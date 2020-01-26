#include "terminal.hxx"
#include "../vga/vga.hxx"
#include "../misc/strlen.hxx"

uint8_t terminal::color = vga::get_color(vga::WHITE, vga::BLACK);
size_t terminal::column = 0;
size_t terminal::row = 0;
uint16_t* const terminal::buffer = (uint16_t*) 0xB8000;


void terminal::putchar(char c, uint8_t color = terminal::color, size_t x = terminal::column, size_t y = terminal::row) {
    const size_t offset = vga::MAX_WIDTH * y + x;
    terminal::buffer[offset] = vga::get_char_entry(c, color);
    ++terminal::column;
    if (terminal::column > vga::MAX_WIDTH) {
        ++terminal::row;
        terminal::column = 0;
    }
}

void terminal::clear() {
    auto color = vga::get_color(vga::LIGHT_GREY, vga::BLACK);
    for (auto offset = 0; offset < vga::MAX_WIDTH * vga::MAX_HEIGHT; ++offset) {
        terminal::buffer[offset] = vga::get_char_entry(' ', color);
    }
}

void terminal::putstr(const char str[], uint8_t color = terminal::color, size_t x = terminal::column, size_t y = terminal::row) {
    size_t len = strlen(str);
    for (auto i = 0; i < len; ++i) {
        terminal::putchar(str[i]);
    }
}