/* Multiboot header Constants */
.set ALIGN,     1<<0
.set MEMINFO,   1<<1
.set FLAGS,     ALIGN | MEMINFO
.set MAGIC,     0x1BADB002
.set CHECKSUM,  -(MAGIC + FLAGS)

/* Multiboot header itself */
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

/* Stack allocation */
.section .bss
.align 16
stack_bottom:
.skip 16384 # Stack frame size
stack_top:

/* Kernel Initialization */
.section .text
.global _start
.type _start, @function
_start:
    /* Set stack pointer */
    mov $stack_top, %esp

    /* TODO: Load GDT */

    call kernel_main

    cli
1:  hlt
    jmp 1b

.size _start, . - _start
