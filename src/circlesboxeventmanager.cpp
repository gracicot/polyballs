#include "circlesboxeventmanager.h"

#include "circlesboxcontextmanager.h"
#include "mouseevent.h"
#include "keypressedeventargs.h"
#include "circleobject.h"
#include "collisioneventargs.h"

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
					Box* targetBox = _contextManager->boxHitTest(args->getPosition());
					if(targetBox != nullptr)
					{
						_contextManager->createTempCircle(args->getPosition());
					}
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
	else if(eventType == "collision")
	{
		const CollisionEventArgs* args = dynamic_cast<const CollisionEventArgs*>(eventArgs);

		if(args != nullptr)
		{
			if(args->getCircle().momentum().getLenght()  > 100000)
			{
				_contextManager->breakCircle(&args->getCircle(), args->getResult().distance.getAngle());
			}
		}
	}
	else if(eventType == "keyPressed")
	{
		const KeyPressedEventArgs* args = dynamic_cast<const KeyPressedEventArgs*>(eventArgs);

		if(args != nullptr)
		{
			switch(args->getKey())
			{
			case sf::Key::Add:
				_contextManager->setBoxSpeed(_contextManager->getBoxSpeed() + 0.05);
				break;

			case sf::Key::Subtract:
				_contextManager->setBoxSpeed(_contextManager->getBoxSpeed() - 0.05);
				break;
			}
		}
	}
}
