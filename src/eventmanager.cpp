#include "eventmanager.h"

#include <tuple>
#include "eventargs.h"

std::queue<std::tuple<std::string, const EventArgs*>> EventManager::_events;

EventManager::EventManager()
{

}

EventManager::~EventManager()
{

}

void EventManager::triggerEvent(std::string eventType, const EventArgs& eventArgs)
{
	_events.push(std::make_tuple(eventType, &eventArgs));
}

void EventManager::execute(const float time)
{
	std::tuple<std::string, const EventArgs*> event;
	while(!_events.empty())
	{
		event = _events.front();
		_events.pop();
		
		handleEvent(std::get<0>(event), std::get<1>(event));
	}
}