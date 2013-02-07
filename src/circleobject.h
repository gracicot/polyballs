#ifndef CIRCLEOBJECT_H
#define CIRCLEOBJECT_H

#include <subgine/physic.hpp>
#include <subgine/collision.hpp>

#include "circledrawer.h"

class CircleObject : public PhysicPoint, public Collisionnable::Circle, public CircleDrawer, public virtual Traits::Radius
{
public:
    CircleObject() = default;
    virtual ~CircleObject();
	
	void setRadius(double radius);
};

#endif // CIRCLEOBJECT_H
