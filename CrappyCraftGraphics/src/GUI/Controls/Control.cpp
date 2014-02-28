#include "Control.h"

GUI::Controls::Control::Control()
{
}

GUI::Controls::Control::Control(int id, Vec2d position, Vec2d size, bool visible, bool enabled)
	: mID(id), mPosition(position), mSize(size), mVisible(visible), mEnabled(enabled)
{
}
