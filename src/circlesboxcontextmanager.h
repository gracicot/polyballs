#ifndef CIRCLESBOXCONTEXTMANAGER_H
#define CIRCLESBOXCONTEXTMANAGER_H

#include "contextmanager.h"

class CircleObject;

class CirclesBoxContextManager : public ContextManager
{
public:
	
	
private:
	std::vector<CircleObject*> _circles;
};

#endif // CIRCLESBOXCONTEXTMANAGER_H
