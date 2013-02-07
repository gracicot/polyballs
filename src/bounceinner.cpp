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
		
// 		point->setPosition(nearest - point->getPosition());
		
		std::cerr << nearest - point->getPosition() << std::endl;
	}
	else
	{
		throw std::runtime_error("can't convert current collisionnable to PhysicPoint...");
	}
}
