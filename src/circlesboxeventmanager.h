#ifndef CIRCLESBOXEVENTMANAGER_H
#define CIRCLESBOXEVENTMANAGER_H

#include "eventmanager.h"

class CirclesBoxContextManager;

class CirclesBoxEventManager : public EventManager
{
public:
	CirclesBoxEventManager();
	virtual ~CirclesBoxEventManager();
	
    virtual void handleEvent(std::string eventType, const EventArgs* eventArgs);
	
private:
	CirclesBoxContextManager* _contextManager;
};

#endif // CIRCLEBOXEVENTMANAGER_H
