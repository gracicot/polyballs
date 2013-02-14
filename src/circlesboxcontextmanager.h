#ifndef CIRCLESBOXCONTEXTMANAGER_H
#define CIRCLESBOXCONTEXTMANAGER_H

#include "contextmanager.h"
#include "box.h"
#include "circlesboxeventmanager.h"

class SpringDrawer;
class CircleObject;

class CirclesBoxContextManager : public ContextManager
{
public:
    CirclesBoxContextManager();
    virtual ~CirclesBoxContextManager();
	
	void addCicle(CircleObject* cicle);
	void removeCicle(CircleObject* cicle);
	CircleObject* circleHitTest(const Vector2 point);
	const CircleObject* circleHitTest(const Vector2 point) const;
	
    virtual void execute(const float time);
    virtual void setViewManager(ViewManager& viewManager);
	
	void setSpring(CircleObject* circle, Vector2 position);
	void setSpringPosition(CircleObject* circle, Vector2 position);
	void unsetSpring(CircleObject* circle);
	
	Box& getBox();
	
	void createTempCircle(const Vector2 position);
	void applyTempCircle();
	void setTempCircleRadiusByPoint(const Vector2 position);
	
	void breakCircle(CircleObject* circle, double angle);
	
private:
	CirclesBoxEventManager _eventManager;
	
	Box _box;
	std::list<CircleObject*> _circles;
	
	CircleObject* _tempCircle;
};

#endif // CIRCLESBOXCONTEXTMANAGER_H
