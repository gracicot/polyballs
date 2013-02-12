#include "circlesboxeventmanager.h"

#include "circlesboxcontextmanager.h"
#include "mouseevent.h"
#include "keypressedeventargs.h"
#include "circleobject.h"

CirclesBoxEventManager::CirclesBoxEventManager()
{

}

CirclesBoxEventManager::~CirclesBoxEventManager()
{

}

CirclesBoxContextManager& CirclesBoxEventManager::getContextManager()
{
	return *_contextManager;
}

const CirclesBoxContextManager& CirclesBoxEventManager::getContextManager() const
{
	return *_contextManager;
}

void CirclesBoxEventManager::setContextManager(CirclesBoxContextManager& contextManager)
{
	_contextManager = &contextManager;
}

void CirclesBoxEventManager::handleEvent(std::string eventType, const EventArgs* eventArgs)
{
	if(eventType == "mouse")
	{
		const MouseEvent* args = dynamic_cast<const MouseEvent*>(eventArgs);

		if(args != nullptr)
		{
			if(args->getType() == MouseEventType::Click)
			{
				_targetCircle = _contextManager->circleHitTest(args->getPosition());
				if(_targetCircle == nullptr)
				{
					_contextManager->createTempCircle(args->getPosition());
				}
				else
				{
					_contextManager->setSpring(_targetCircle, args->getPosition());
				}
			}
			else if(args->getType() == MouseEventType::Drag)
			{
				if(_targetCircle == nullptr)
				{
					_contextManager->setTempCircleRadiusByPoint(args->getPosition());
				}
				else
				{
					_contextManager->setSpringPosition(_targetCircle, args->getPosition());
				}
			}
			else if(args->getType() == MouseEventType::Unclick)
			{
				if(_targetCircle == nullptr)
				{
					_contextManager->applyTempCircle();
				}
				else
				{
					_contextManager->unsetSpring(_targetCircle);
				}
			}
		}
	}
	else if(eventType == "keyPressed")
	{
		const KeyPressedEventArgs* args = dynamic_cast<const KeyPressedEventArgs*>(eventArgs);

		if(args != nullptr)
		{

		}
	}
}
