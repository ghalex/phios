/*
 *  CppSupport.cpp
 *
 *  Created on: Jun 3, 2009
 *      Author: ghalex
 */


/* Defined in the linker. */
extern unsigned long startCtors;
extern unsigned long endCtors;

extern unsigned long startDtors;
extern unsigned long endDtors;

namespace phi {
namespace kernel {
namespace compiler {


	/**
	 * Calls the constructors for all global objects.
	 * Call this before using any global objects.
	 *
	 * @return
	 */
	void callConstructors()
	{
		unsigned long *start = &startCtors;
		unsigned long *end   = &endCtors;

		while( start < end)
		{
			void (*fp)(void) = reinterpret_cast<void (*)(void)>(*start);
			fp();

			start++;
		}
	}


	/**
	 * Calls the destructor for all global objects.
	 *
	 * @return
	 */
	void callDestructos()
	{
		unsigned long *start = &startDtors;
		unsigned long *end   = &endDtors;

		while( start < end)
		{
			void (*fp)(void) = reinterpret_cast<void (*)(void)>(*start);
			fp();

			start++;
		}
	}

	extern "C" void __cxa_atexit(void (*f)(void *), void *p, void *d)
	{
	}

}
}
}
