#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <string>

class EventArgs;

class EventManager
{
public:
    EventManager();
    virtual ~EventManager();
	
	static void triggerEvent(std::string eventType, const EventArgs& aventArgs);
	
protected:
	
private:
};

#endif // EVENTMANAGER_H
