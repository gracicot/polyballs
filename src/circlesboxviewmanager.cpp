#include "circlesboxviewmanager.h"

#include "boxdrawer.h"

CirclesBoxViewManager::CirclesBoxViewManager() : _box(nullptr)
{

}

CirclesBoxViewManager::~CirclesBoxViewManager()
{

}

void CirclesBoxViewManager::render(sf::RenderTarget& taget) const
{
	taget.Draw(*_box);
	for(auto& cicle : _circles)
	{
		taget.Draw(cicle);
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
