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
    	startCtors = .; _startCtors = .; __startCtors = .;
        *(.ctors)
        endCtors = .; _endCtors = .; __endCtors = .;
         
        startDtors = .; _startDtors = .; __startDtors = .;
   		*(.dtor*)
   		endDtors = .; _endDtors = .; __endDtors = .;
   
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
