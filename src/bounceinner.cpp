#include "bounceinner.h"
#include "circleobject.h"
#include "eventmanager.h"
#include "collisioneventargs.h"
#include "box.h"

Bounce::Bounce()
{

}

Bounce::~Bounce()
{

}

void Bounce::apply(Collisionnable::Collisionnable& object, const Collisionnable::Collisionnable& other, CollisionResult& result)
{
	SatResult* sat = dynamic_cast<SatResult*>(&result);
	CircleObject* point = dynamic_cast<CircleObject*>(&object);
	const Box* box = nullptr;

	if(!(box = dynamic_cast<const Box*>(&other)))
	{
		return;
	}

	if(point != nullptr && point != 0 && sat != nullptr && sat != 0)
	{
			Vector2 nearest = sat->distance;
			

			//point->setPosition(point->getPosition() + nearest);
			point->setPulse("collision", nearest * point->getMass() * 10);

			EventManager::triggerEvent("collision", new CollisionEventArgs(*sat, *point));
		
	}
}
