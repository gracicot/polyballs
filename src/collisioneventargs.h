#ifndef COLLISIONEVENTARGS_H
#define COLLISIONEVENTARGS_H

#include <subgine/collision.hpp>

#include "eventargs.h"
#include "circleobject.h"

class CollisionEventArgs : public EventArgs
{
public:
	CollisionEventArgs(SatResult& result, CircleObject& circle);
	virtual ~CollisionEventArgs();
	
	const SatResult& getResult() const;
	const CircleObject& getCircle() const;
	
private:
	SatResult& _result;
	CircleObject& _circle;
};

#endif // COLLISIONEVENTARGS_H
