#ifndef COLLISIONSQUARE_H
#define COLLISIONSQUARE_H

#include <subgine/system.hpp>
#include <subgine/collision.hpp>

class CollisionSquare : public virtual Collisionnable::Polygon, public virtual Traits::Position, public virtual Traits::Angle, public virtual Traits::Vertex
{
public:
	CollisionSquare() = default;
	virtual ~CollisionSquare() = default;
	CollisionSquare(const CollisionSquare&) = delete;
	
	void setRotationPoint(Vector2 position);
	
    void setDimensions(Vector2 dimensions);
	void setPosition(Vector2 position);
	void setAngle(double angle);
	
protected:
	
private:
};

#endif // COLLISIONSQUARE_H
