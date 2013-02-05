#ifndef CIRCLEOBJECT_H
#define CIRCLEOBJECT_H

#include <subgine/physic.hpp>
#include <subgine/collision.hpp>

#include "circledrawer.h"

class CircleObject : public PhysicPoint, public Collisionnable::Circle, public CircleDrawer
{
    CircleObject() = default;
    ~CircleObject() = default;
};

#endif // CIRCLEOBJECT_H
