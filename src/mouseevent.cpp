#include "mouseevent.h"

MouseEvent::MouseEvent(MouseEventType::MouseEventType type, Vector2 position): _type(type), _position(position)
{
	
}

MouseEvent::~MouseEvent()
{

}

Vector2 MouseEvent::getPosition() const
{
	return _position;
}

MouseEventType::MouseEventType MouseEvent::getType() const
{
	return _type;
}


void MouseEvent::setPosition(Vector2 position)
{
	_position = position;
}

void MouseEvent::setType(MouseEventType::MouseEventType type)
{
	_type = type;
}
