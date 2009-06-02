/*
 * Kernel.cpp
 *
 *  Created on: Jun 2, 2009
 *      Author: ghalex
 */

#include "Kernel.h"

namespace phi {
namespace kernel {

	using namespace drivers;

	video::Text Kernel::out;

	Kernel::Kernel()
	{
	}

	Kernel::~Kernel()
	{
	}

	void Kernel::initialize()
	{
		video::Text videoDriver;

		videoDriver.clear();
		videoDriver.write("Un test");
	}
}
}
