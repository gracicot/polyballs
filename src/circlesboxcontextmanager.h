#ifndef CIRCLESBOXCONTEXTMANAGER_H
#define CIRCLESBOXCONTEXTMANAGER_H

#include "contextmanager.h"
#include "box.h"

class CircleObject;

class CirclesBoxContextManager : public ContextManager
{
public:
    CirclesBoxContextManager();
    virtual ~CirclesBoxContextManager();
	
	void addCicle(CircleObject* cicle);
	void removeCicle(CircleObject* cicle);
	
    virtual void execute(const float time);
	
    virtual void setViewManager(ViewManager& viewManager);
	
	Box& getBox();
	
private:
	Box _box;
	std::list<CircleObject*> _circles;
};

#endif // CIRCLESBOXCONTEXTMANAGER_H
