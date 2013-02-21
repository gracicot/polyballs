#include "eventmanager.h"

#include <tuple>
#include "eventargs.h"

std::queue<std::pair<std::string, const EventArgs*>> EventManager::_events;

EventManager::EventManager()
{

}

EventManager::~EventManager()
{

}

void EventManager::triggerEvent(std::string eventType, const EventArgs* eventArgs)
{
	sf::Lock lock(MainEngine::mutex());
	_events.push(std::pair<std::string, const EventArgs*>(eventType, eventArgs));
}

void EventManager::execute(const float time)
{
	sf::Lock lock(MainEngine::mutex());
	
	std::pair<std::string, const EventArgs*> event;
	while(!_events.empty())
	{
		event = _events.front();
		_events.pop();
		
		handleEvent(event.first, event.second);
		
		delete event.second;
	}
}