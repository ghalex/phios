/*
 *  Compiler.cpp
 *
 *  Created on: Jun 3, 2009
 *      Author: ghalex
 */

#include "Compiler.h"
#include "CppSupport.h"

namespace phi {
namespace kernel {
namespace compiler {

	Compiler::Compiler()
	{
	}

	Compiler::~Compiler()
	{
	}


	void Compiler::initialize()
	{
	}

	void Compiler::enableGlobalObjects()
	{
		callConstructors();
	}


}
}
}
