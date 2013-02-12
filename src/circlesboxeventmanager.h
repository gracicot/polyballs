#ifndef CIRCLESBOXEVENTMANAGER_H
#define CIRCLESBOXEVENTMANAGER_H

#include "eventmanager.h"

class CircleObject;
class CirclesBoxContextManager;

class CirclesBoxEventManager : public EventManager
{
public:
	CirclesBoxEventManager();
	virtual ~CirclesBoxEventManager();
	
    virtual void handleEvent(std::string eventType, const EventArgs* eventArgs);
	
	void setContextManager(CirclesBoxContextManager& contextManager);
	
	CirclesBoxContextManager& getContextManager();
	const CirclesBoxContextManager& getContextManager() const;
	
private:
	CircleObject* _targetCircle;
	CirclesBoxContextManager* _contextManager;
};

#endif // CIRCLEBOXEVENTMANAGER_H
