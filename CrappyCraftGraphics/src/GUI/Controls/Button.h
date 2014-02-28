#ifndef BUTTON_H
#define BUTTON_H
#include "../Vectors/Vec2.h"
#include "Control.h"
#include <string>

namespace GUI
{
	namespace Controls
	{
		class Button : public Control
		{
		public:
			Button();

			/// <summary>
			///     The string displayed on this button.
			/// </summary>
			std::string mText;

		private:
		};
	}
}

#endif