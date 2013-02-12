#ifndef CIRCLESBOXVIEWMANAGER_H
#define CIRCLESBOXVIEWMANAGER_H

#include "viewmanager.h"

class BoxDrawer;
namespace Rule{class Spring;}
class SpringDrawer;
class CircleObject;

class CirclesBoxViewManager : public ViewManager
{
public:
    CirclesBoxViewManager();
    virtual ~CirclesBoxViewManager();
	
	void render(sf::RenderTarget& taget) const;
	
	void addCicle(const CircleDrawer& cicle);
	void removeCicle(const CircleDrawer& cicle);
	
	void setSpring(const CircleObject& circle, const Rule::Spring& spring);
	
	void setBox(BoxDrawer& box);
	BoxDrawer& getBox();
	
private:
	SpringDrawer* _spring;
	std::list<const CircleDrawer*> _circles;
	BoxDrawer* _box;
};

#endif // CIRCLESBOXVIEWMANAGER_H
