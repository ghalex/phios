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

	void Kernel::main()
	{
		Kernel::out.clear();
		Kernel::out.write("Static objects works! Hehe");
	}
}
}
