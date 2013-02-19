#ifndef BOUNCEINNER_H
#define BOUNCEINNER_H

#include <subgine/system.hpp>
#include <subgine/collision.hpp>
#include <subgine/physic.hpp>

class Bounce : public CollisionHandler
{
public:
    Bounce();
    virtual ~Bounce();
	
    virtual void apply(Collisionnable::Collisionnable& object, const Collisionnable::Collisionnable& other, CollisionResult& result);
};

#endif // BOUNCEINNER_H
