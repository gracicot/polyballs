#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <string>
#include <queue>
#include <condition_variable>
#include <subgine/system.hpp>

class EventArgs;

class EventManager : public Engine
{
public:
    EventManager();
    virtual ~EventManager();
	
	static void triggerEvent(std::string eventType, const EventArgs* eventArgs);
	
    virtual void execute(const float time);
	
	virtual void handleEvent(std::string eventType, const EventArgs* eventArgs) = 0;
	
private:
	std::condition_variable _condition;
	static std::queue<std::pair<std::string, const EventArgs*>> _events;
	
};

#endif // EVENTMANAGER_H
