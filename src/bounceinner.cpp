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
	const CircleObject* other_circle = nullptr;


	if(point != nullptr && point != 0 && sat != nullptr && sat != 0)
	{
		if((other_circle = dynamic_cast<const CircleObject*>(&other)))
		{
			Vector2 nearest = sat->distance;
			nearest.setAngle(( point->getPosition() - other_circle->getPosition()).getAngle());

			point->setPulse("collision", nearest * point->getMass() * other_circle->getMass() / 400);

			EventManager::triggerEvent("collision", new CollisionEventArgs(*sat, *point));
		}
		else
		{
			Vector2 nearest = sat->distance;
			Vector2 velocity = point->getVelocity();
				point->setPosition(point->getPosition() + nearest);
			

			velocity.setAngle((2*(nearest.getAngle()+(pi/2))) - velocity.getAngle());
			point->setVelocity(velocity);
			//point->setPulse("collision", nearest * point->getMass()*100);

			EventManager::triggerEvent("collision", new CollisionEventArgs(*sat, *point));
		}
	}
}
