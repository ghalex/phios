/*
 * Kernel.h
 *
 *  Created on: Jun 2, 2009
 *      Author: ghalex
 */

#ifndef KERNEL_H_
#define KERNEL_H_

#include "video/Text.h"

namespace phi {
namespace kernel {

	using namespace drivers;

	class Kernel
	{
		// Members
		public:
			static video::Text out;

		// Functions
		public:
			Kernel();
			~Kernel();

			void initialize();
	};

}
}

#endif /* KERNEL_H_ */
