#include "bounceinner.h"
#include "circleobject.h"

BounceInner::BounceInner()
{

}

BounceInner::~BounceInner()
{

}

void BounceInner::apply(Collisionnable::Collisionnable& object, const Collisionnable::Collisionnable& other, CollisionResult& result)
{
	SatResult* sat = dynamic_cast<SatResult*>(&result);
	CircleObject* point = dynamic_cast<CircleObject*>(&object);
	if(point != nullptr && point != 0 && sat != nullptr && sat != 0)
	{
		Vector2 nearest = sat->distance;
		
		nearest.setAngle(nearest.getAngle()-(pi/2));
		
		//if(nearest.getLenght() < point->getRadius())
		point->setPulse("collisionInner", nearest*point->getMass()*100);
	}
	else
	{
		throw std::runtime_error("can't convert current collisionnable to PhysicPoint...");
	}
}
