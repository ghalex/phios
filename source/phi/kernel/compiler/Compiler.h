/*
 *  Compiler.h
 *
 *  Created on: Jun 3, 2009
 *      Author: ghalex
 */

#ifndef COMPILER_H_
#define COMPILER_H_

namespace phi {
namespace kernel {
namespace compiler {

	class Compiler
	{
		public:
			Compiler();
			~Compiler();

			void initialize();
			void enableGlobalObjects();

	};

}
}
}

#endif /* COMPILER_H_ */
