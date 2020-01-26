CC := i686-elf-gcc
CXX := i686-elf-g++
ASM := i686-elf-as

CFLAGS = -ffreestanding -O2 -nostdlib -Wall -Wextra
CXXFLAGS = -ffreestanding -O2 -nostdlib -fno-exceptions -fno-rtti -Wall -Wextra -std=c++14

out/luszos.bin: out/kernel.o out/boot.o out/strlen.o out/terminal.o out/vga.o
	$(CXX) -T linker.ld -o $@ $(CXXFLAGS) $^ -lgcc

out/kernel.o: kernel/kernel.cc
	$(CXX) -c $^ $(CXXFLAGS) -o $@

out/terminal.o: kernel/terminal/terminal.cc
	$(CXX) -c $< $(CXXFLAGS) -o $@

out/vga.o: kernel/vga/vga.cc
	$(CXX) -c $< $(CXXFLAGS) -o $@

out/strlen.o: kernel/misc/strlen.cc
	$(CXX) -c $< $(CXXFLAGS) -o $@

out/boot.o: kernel/arch/i686/boot.asm
	$(ASM) $< -o $@

clean:
	rm out/*