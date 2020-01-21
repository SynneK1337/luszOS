CC := i686-elf-gcc
CXX := i686-elf-g++
ASM := i686-elf-as

SRC := $(wildcard *.cc)
OBJ := $(patsubst %.cc, %.o, $(SRC))

CXXFLAGS = -ffreestanding -O2 -nostdlib -Wall -Wextra

link: $(OBJ)
	$(CXX) -T linker.ld -o out/luszos.bin $(CXXFLAGS) out/boot.o out/kernel.o -lgcc

%.o: %.cc
	$(CXX) $< $(CXXFLAGS) -o $@

boot: arch/i686/boot.asm
	$(ASM) arch/i686/boot.asm -o out/boot.o

clean:
	rm out/*