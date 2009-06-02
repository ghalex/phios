/*
 * Text.h
 *
 *  Created on: Jun 2, 2009
 *      Author: ghalex
 */

#ifndef TEXT_H_
#define TEXT_H_

namespace phi {
namespace kernel {
namespace drivers {
namespace video {

	class Text
	{
		public:
			Text();
			~Text();

			void clear();
			void write(char *string);
			void writeln(char *string);
			void putc(char c);
			void moveCursor();

		private:
			unsigned short *videoMemory;
			unsigned short blank;

			int attrib;
			int cursorX;
			int cursorY;
	};

}
}
}
}

#endif /* TEXT_H_ */
