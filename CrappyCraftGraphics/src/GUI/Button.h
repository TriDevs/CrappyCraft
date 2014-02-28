#ifndef BUTTON_H
#define BUTTON_H

#include <string>

namespace GUI
{
	namespace Controls
	{
		class Button
		{
		public:
			Button();


			/// <summary>
			///     The string displayed on this button.
			/// </summary>
			std::string mText;

			/// <summary>
			///     The ID of this button, used as reference.
			/// </summary>
			int mID;

			/// <summary>
			///     Position of the button.
			/// </summary>


		private:
		};
	}
}

#endif