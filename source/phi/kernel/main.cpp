/*
 * main.cpp
 *
 *  Created on: Apr 13, 2009
 *      Author: ghalex
 */

#include "Kernel.h"
#include "Compiler.h"

using namespace phi;
using namespace kernel;
using namespace compiler;

Kernel kernelObj;

extern "C" void _main( struct multiboot_data* mbd, unsigned int magic )
{
	Compiler compiler;
	compiler.enableGlobalObjects();

	kernelObj.main();

}
