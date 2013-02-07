#ifndef CIRCLESBOXCONTEXTMANAGER_H
#define CIRCLESBOXCONTEXTMANAGER_H

#include "contextmanager.h"
#include "box.h"
#include "circlesboxeventmanager.h"

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
	
	void createTempCircle(Vector2 position);
	void applyTempCircle();
	void setTempCircleRadiusByPoint(Vector2 position);
	
private:
	CirclesBoxEventManager _eventManager;
	
	Box _box;
	std::list<CircleObject*> _circles;
	
	CircleObject* _tempCircle;
};

#endif // CIRCLESBOXCONTEXTMANAGER_H
