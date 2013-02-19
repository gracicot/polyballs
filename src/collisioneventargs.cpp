#include "collisioneventargs.h"

CollisionEventArgs::CollisionEventArgs(SatResult& result, CircleObject& circle) : _result(result), _circle(circle)
{
	
}

const SatResult& CollisionEventArgs::getResult() const
{
	return _result;
}

CircleObject& CollisionEventArgs::getCircle() const
{
	return _circle;
}

CollisionEventArgs::~CollisionEventArgs()
{

}
