#ifndef BOX_H
#define BOX_H

#include <subgine/system.hpp>
#include <subgine/collision.hpp>
#include <subgine/physic.hpp>

#include "boxdrawer.h"
#include "collisionsquare.h"

class CollisionSquare;

class Box : public virtual Collisionnable::Polygon, public BoxDrawer, public virtual Traits::Position, public virtual Traits::Angle, public virtual Traits::Vertex
{
public:
    Box();
    virtual ~Box();
	
    virtual void setDimensions(Vector2 dimensions);
	void setPosition(Vector2 position);
	void setAngle(double angle);
	double getAngle() const;
	
	std::vector<CollisionSquare>& collisionsSquares();
	const std::vector<CollisionSquare>& collisionsSquares() const;
	
protected:
	
private:
	std::vector<CollisionSquare> _collisionSqares;
};



#endif // BOX_H
