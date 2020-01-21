#include <stdint.h>

void kernel_main(void) {
    uint16_t* framebuffer = (uint16_t*) 0xB8000;
    for (short i = 0; i < 4; ++i) {
        framebuffer[i] = 'A' | (15 | 0 << 4) << 8;
    }
}