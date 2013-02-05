#include "circlesboxcontextmanager.h"

#include "circlesboxviewmanager.h"
#include "circleobject.h"
#include "box.h"

CirclesBoxContextManager::CirclesBoxContextManager()
{

}

CirclesBoxContextManager::~CirclesBoxContextManager()
{

}

void CirclesBoxContextManager::addCicle(CircleObject& cicle)
{
	_circles.push_back(&cicle);
	((CirclesBoxViewManager*)(_viewManager))->addCicle(cicle);
}

Box& CirclesBoxContextManager::getBox()
{
	return *_box;
}

void CirclesBoxContextManager::removeCicle(CircleObject& cicle)
{
	_circles.remove(&cicle);
	((CirclesBoxViewManager*)(_viewManager))->removeCicle(cicle);
	
}

void CirclesBoxContextManager::setBox(Box& box)
{
	_box = &box;
	((CirclesBoxViewManager*)(_viewManager))->setBox(box);
}
