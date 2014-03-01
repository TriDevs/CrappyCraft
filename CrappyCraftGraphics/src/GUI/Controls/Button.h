#ifndef BUTTON_H
#define BUTTON_H
#include "../../Vectors/Vec2.h"
#include "Control.h"
#include <string>

namespace Graphics
{
	namespace Controls
	{
		class Button : public Control
		{
		public:
			Button();
			Button(int id, Vec2d position, Vec2d size, std::string text, bool visible = 1,
				bool enabled = 1);

			void Render();

			/// <summary>
			///     The string displayed on this button.
			/// </summary>
			std::string mText;

		private:
		};
	}
}

#endif