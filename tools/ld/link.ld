OUTPUT_FORMAT("pe-i386")

ENTRY(entry)
SECTIONS
{
    .text 0x100000 :
    {
        code = .; _code = .; __code = .;
        *(.text)
        . = ALIGN(4096);
    }
    
    .data :
    {
    	start_ctors = .; _start_ctors = .; __start_ctors = .;
        *(.ctors)
        end_ctors = .; _end_ctors = .; __end_ctors = .;
         
        start_dtors = .; _start_dtors = .; __start_dtors = .;
   		*(.dtor*)
   		end_dtors = .; _end_dtors = .; __end_dtors = .;
   
        data = .; _data = .; __data = .;
        *(.data)
        *(.rodata)
        . = ALIGN(4096);
    }

    .bss :
    {
        bss = .; _bss = .; __bss = .;
        *(.bss)
        . = ALIGN(4096);
    }

    end = .; _end = .; __end = .;
}
