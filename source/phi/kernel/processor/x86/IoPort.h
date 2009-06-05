/*
 * IoPort.h
 *
 *  Created on: Jun 5, 2009
 *      Author: ghalex
 */

#ifndef IOPORT_H_
#define IOPORT_H_

#include "string.h"

namespace phi {
namespace kernel {
namespace processor {
namespace x86 {


	class IoPort
	{
		public:
			IoPort();
			~IoPort();

			unsigned char read8(size_t offset = 0);
			unsigned short read16(size_t offset = 0);

			void write8(unsigned char data, size_t offset = 0);
			void write16(unsigned short data, size_t offset = 0);

			bool allocate(size_t port, size_t size);
			void free();

		private:

			// The base I/O port
			size_t ioPort;

			// The number of successive I/O ports
			size_t ioSize;
	};

}
}
}
}

#endif /* IOPORT_H_ */
