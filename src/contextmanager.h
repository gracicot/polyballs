#ifndef CONTEXTMANAGER_H
#define CONTEXTMANAGER_H

#include "viewmanager.h"
#include "circleobject.h"

class ContextManager
{
private:
	std::vector<CircleObject*> _circles;
	ViewManager* _viewManager;
};

#endif // CONTEXTMANAGER_H
