# phios master makefile

# Directories
BOOT_DIR	= boot
KERNEL_DIR	= kernel
BIN_DIR		= ../../bin
TOOLS_DIR	= ../../tools

# Macros
LDSCRIPT 	= $(TOOLS_DIR)/ld/link.ld
LDFLAGS 	= -T $(LDSCRIPT)

# Objects
BOOT_OBJECTS = $(BOOT_DIR)/boot.o
KERNEL_OBJECTS =  $(KERNEL_DIR)/Kernel.a

# Build kernel
all:
	cd $(BOOT_DIR) && $(MAKE) $@
	cd $(KERNEL_DIR) && $(MAKE) $@
	$(LD) $(LDFLAGS) -o $(BIN_DIR)/kernel.bin $(BOOT_OBJECTS) $(KERNEL_OBJECTS)

clean:
	cd $(BOOT_DIR) && $(MAKE) $@
	cd $(KERNEL_DIR) && $(MAKE) $@
	cd $(BIN_DIR) && rm -f kernel.bin