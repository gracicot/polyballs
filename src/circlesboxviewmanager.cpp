#include "circlesboxviewmanager.h"

#include "boxdrawer.h"
#include "springdrawer.h"
#include "circleobject.h"

CirclesBoxViewManager::CirclesBoxViewManager() : _box(nullptr), _spring(nullptr)
{

}

CirclesBoxViewManager::~CirclesBoxViewManager()
{

}

void CirclesBoxViewManager::render(sf::RenderTarget& taget) const
{
	if(_box != nullptr)
	{
		taget.Draw(*_box);
	}

for(auto cicle : _circles)
	{
		taget.Draw(*cicle);
	}

	if(_spring != nullptr)
	{
		taget.Draw(*_spring);
	}
}

void CirclesBoxViewManager::setSpring(const CircleObject& circle, const Rule::Spring& spring)
{
	if(_spring != nullptr)
	{
		delete _spring;
		_spring = nullptr;
	}
	_spring = new SpringDrawer(spring, circle, 0.1);
}

void CirclesBoxViewManager::unsetSpring()
{
	if(_spring != nullptr)
	{
		delete _spring;
		_spring = nullptr;
	}
}

void CirclesBoxViewManager::addCicle(const CircleDrawer& cicle)
{
	_circles.push_back(&cicle);
}

BoxDrawer& CirclesBoxViewManager::getBox()
{
	return *_box;
}

void CirclesBoxViewManager::removeCicle(const CircleDrawer& cicle)
{
	_circles.remove(&cicle);
}

void CirclesBoxViewManager::setBox(BoxDrawer& box)
{
	_box = &box;
}
