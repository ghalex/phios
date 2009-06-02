[BITS 32]
MBOOT_PAGE_ALIGN    	equ 1 << 0    			; Load kernel and modules on a page boundary
MBOOT_MEM_INFO      	equ 1 << 1    			; Provide your kernel with memory info
MULTIBOOT_AOUT_KLUDGE	equ 1<<16

MBOOT_HEADER_MAGIC  	equ 0x1BADB002 			; Multiboot Magic value
MBOOT_HEADER_FLAGS  	equ MBOOT_PAGE_ALIGN | MBOOT_MEM_INFO | MULTIBOOT_AOUT_KLUDGE
MBOOT_CHECKSUM      	equ -(MBOOT_HEADER_MAGIC + MBOOT_HEADER_FLAGS)
EXTERN code, bss, end

[SECTION .text]
mboot:
	dd	MBOOT_HEADER_MAGIC
	dd	MBOOT_HEADER_FLAGS
	dd	MBOOT_CHECKSUM

; AOUT kludge - must be physical addresses. Make a note of these:
; The linker script fills in the data for these ones!
    dd mboot
    dd code
    dd bss
    dd end
    dd entry

; reserve initial kernel stack space
STACKSIZE equ 0x4000                  		; that's 16k.

[GLOBAL entry]                  			; Kernel entry point.
[EXTERN __main]
entry:
    mov 	esp, stack + STACKSIZE          ; set up the stack
    push	eax								; Push multiboot magic value
    push	ebx								; Push ptr to multiboot structure

    ; Execute the kernel:
    cli                         			; Disable interrupts.
    call __main                   			; call _main() function.
    jmp $                       			; Enter an infinite loop, to stop the processor.
                                			; executing whatever rubbish is in the memory
                                			; after our kernel!

[SECTION .bss]
stack:
   resb STACKSIZE                     		; reserve 16k stack on a quadword boundary
