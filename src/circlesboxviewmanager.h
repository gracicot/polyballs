#ifndef CIRCLESBOXVIEWMANAGER_H
#define CIRCLESBOXVIEWMANAGER_H

#include "viewmanager.h"

class CirclesBoxViewManager : public ViewManager
{
	
private:
	std::vector<CircleDrawer*> _circles;
	
};

#endif // CIRCLESBOXVIEWMANAGER_H
