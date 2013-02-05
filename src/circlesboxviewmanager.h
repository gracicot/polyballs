#ifndef CIRCLESBOXVIEWMANAGER_H
#define CIRCLESBOXVIEWMANAGER_H

#include "viewmanager.h"

class BoxDrawer;

class CirclesBoxViewManager : public ViewManager
{
public:
    CirclesBoxViewManager();
    virtual ~CirclesBoxViewManager();
	
	void render(sf::RenderTarget& taget) const;
	
	void addCicle(const CircleDrawer& cicle);
	void removeCicle(const CircleDrawer& cicle);
	
	void setBox(BoxDrawer& box);
	BoxDrawer& getBox();
	
private:
	std::list<const CircleDrawer*> _circles;
	BoxDrawer* _box;
};

#endif // CIRCLESBOXVIEWMANAGER_H
