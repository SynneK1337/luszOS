#include "vga/vga.hxx"
#include "terminal/terminal.hxx"

extern "C"
void kernel_main() {
    terminal::clear();
    terminal::color = vga::get_color(vga::LIGHT_GREY, vga::BLACK);
    
    terminal::putstr("luszOS booted up.");
}