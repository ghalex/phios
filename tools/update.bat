@ECHO OFF
ECHO Update phiOS image.
objcopy-elf -O elf32-i386 ../bin/kernel.bin a:/kernel.bin  
ECHO Image updated. 