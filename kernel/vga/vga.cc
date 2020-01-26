#include "vga.hxx"

uint8_t vga::get_color(enum vga::COLORS fg, enum vga::COLORS bg) {
    return fg | bg << 4;
}

uint16_t vga::get_char_entry(unsigned char c, uint8_t color) {
    return (uint16_t) c | (uint16_t) color << 8;
}