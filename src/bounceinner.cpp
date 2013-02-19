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
			if((other_circle->getPosition() - point->getPosition()).getLenght() < (other_circle->getRadius() + point->getRadius()))
			{
				Vector2 nearest = sat->distance;
				nearest.setAngle((other_circle->getPosition() - point->getPosition()).getAngle());
				nearest.setLenght((-1 * (other_circle->getPosition() - point->getPosition()).getLenght()) + (other_circle->getRadius() + point->getRadius()));


				point->setPulse("collision", nearest * -400);

				EventManager::triggerEvent("collision", new CollisionEventArgs(*sat, *point));
			}
		}
		else
		{
			Vector2 nearest = sat->distance;


			//point->setPosition(point->getPosition() + nearest);
			point->setPulse("collision", nearest * point->getMass() * 40);

			EventManager::triggerEvent("collision", new CollisionEventArgs(*sat, *point));
		}
	}
}
