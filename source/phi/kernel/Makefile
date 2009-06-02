# phios kernel makefile
# Directories
INCLUDE_PATHS = -Idrivers

# Macros
RLIB		= ranlib
GCCFLAGS	= $(INCLUDE_PATHS) -nostartfiles -nostdlib -fno-rtti -fno-exceptions

# Objects
DRIVERS_OBJECTS	= drivers/video/Text.o
OBJECTS			= main.o Kernel.o $(DRIVERS_OBJECTS)

# Kernel
KERNEL		= Kernel.a

all: $(KERNEL)

# Arhive core objects
$(KERNEL): $(OBJECTS)
	$(AR) rvu $@ $(OBJECTS)
	$(RLIB) $(KERNEL)
	
#Clear all .o files
clean: 
	rm -f *.o *.a $(OBJECTS)
	
# Compile all .cpp files
.cpp.o:
	g++ $(GCCFLAGS) -c -o $@ $<