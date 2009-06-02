/*
 * main.cpp
 *
 *  Created on: Apr 13, 2009
 *      Author: ghalex
 */

#include "Kernel.h"

using namespace phi;
using namespace kernel;

extern "C" void _main( struct multiboot_data* mbd, unsigned int magic )
{
	Kernel objKernel;
	objKernel.initialize();

}
