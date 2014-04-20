#include "Control.h"

Graphics::Controls::Control::Control()
{
}

Graphics::Controls::Control::Control(int id, Graphics::Vectors::Vec2d position, 
	Graphics::Vectors::Vec2d size, bool visible, bool enabled)
	: mID(id), mPosition(position), mSize(size), mVisible(visible), mEnabled(enabled)
{
}
