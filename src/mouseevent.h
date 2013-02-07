#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include "eventargs.h"
#include <subgine/system.hpp>

namespace MouseEventType
{
	enum MouseEventType{
		Move,
		Click
	};
}

class MouseEvent : public EventArgs
{
public:
    MouseEvent(MouseEventType::MouseEventType type = MouseEventType::Move, Vector2 position = Vector2());
    virtual ~MouseEvent();
	
	void setPosition(Vector2 position);
	void setType(MouseEventType::MouseEventType type);
	
	Vector2 getPosition() const;
	MouseEventType::MouseEventType getType() const;
	
private:
	MouseEventType::MouseEventType _type;
	Vector2 _position;
	
};

#endif // MOUSEEVENT_H
