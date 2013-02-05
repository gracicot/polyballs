#ifndef CIRCLESBOXCONTEXTMANAGER_H
#define CIRCLESBOXCONTEXTMANAGER_H

#include "contextmanager.h"

class Box;
class CircleObject;

class CirclesBoxContextManager : public ContextManager
{
public:
    CirclesBoxContextManager();
    virtual ~CirclesBoxContextManager();
	
	void addCicle(CircleObject& cicle);
	void removeCicle(CircleObject& cicle);
	
	void setBox(Box& box);
	Box& getBox();
	
private:
	Box* _box;
	std::list<CircleObject*> _circles;
};

#endif // CIRCLESBOXCONTEXTMANAGER_H
