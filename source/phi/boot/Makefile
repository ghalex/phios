# phios boot makefile
# Macros
SHELL		= sh
ASM 		= nasm
ASMFLAGS	= -f win32

all: boot.o

#Clear all .o files
clean: 
	rm -f *.o
	
# Assembly all .s files
.s.o:
	$(ASM) $(ASMFLAGS) -o $@ $<