#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

#include "circledrawer.h"

class ViewManager
{
public:
	ViewManager() = default;
	virtual ~ViewManager();
	
	virtual void render(sf::RenderTarget& taget) const =0;
	
private:
};

#endif // VIEWMANAGER_H
