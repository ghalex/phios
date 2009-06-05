/*
 * IoPort.cpp
 *
 *  Created on: Jun 5, 2009
 *      Author: ghalex
 */

#include "IoPort.h"

namespace phi {
namespace kernel {
namespace processor {
namespace x86 {

	IoPort::IoPort() :
		ioPort(0)
	{
	}

	IoPort::~IoPort()
	{
	}

	bool IoPort::allocate(size_t port, size_t size)
	{
		ioPort = port;
		ioSize = size;

		return true;
	}

	void IoPort::free()
	{
		ioPort = 0;
		ioSize = 0;
	}

	/**
	 * Read one byte from I/O ports.
	 *
	 * @param offset
	 * @return readed byte
	 */
	unsigned char IoPort::read8(size_t offset)
	{
	    unsigned char ret;
	    asm volatile("inb %%dx, %%al":"=a" (ret):"d" (ioPort + offset));

	    return ret;
	}

	/**
	 * Read one word from I/O ports.
	 *
	 * @param offset
	 * @return readed word
	 */
	unsigned short IoPort::read16(size_t offset)
	{
		unsigned short ret;
		asm volatile("inw %%dx, %%ax":"=a" (ret):"d" (ioPort + offset));

		return ret;
	}

	/**
	 * Write one byte to I/O ports.
	 *
	 * @param offset
	 * @param data
	 */
	void IoPort::write8(unsigned char data, size_t offset)
	{
	    asm volatile("outb %%al, %%dx"::"d" (ioPort + offset), "a" (data));
	}

	/**
	 * Write one word to I/O ports.
	 *
	 * @param offset
	 * @param data
	 */
	void IoPort::write16(unsigned short data, size_t offset)
	{
		 asm volatile("outw %%ax, %%dx"::"d" (ioPort + offset), "a" (data));
	}


}
}
}
}
