#include "collisionsquare.h"

void CollisionSquare::setDimensions(Vector2 dimensions)
{	
	_vertex.clear();

    _vertex.push_back(Vector2(_position.x - (dimensions.x/2), _position.y - (dimensions.y/2)));
    _vertex.push_back(Vector2(_position.x + (dimensions.x/2), _position.y - (dimensions.y/2)));
    _vertex.push_back(Vector2(_position.x + (dimensions.x/2), _position.y + (dimensions.y/2)));
    _vertex.push_back(Vector2(_position.x - (dimensions.x/2), _position.y + (dimensions.y/2)));
}

void CollisionSquare::setPosition(Vector2 position)
{
	_position = position;
}

void CollisionSquare::setAngle(double angle)
{
	_angle = angle;
}

void CollisionSquare::setRotationPoint(Vector2 position)
{
	_position += position;
	for(auto& vertex : _vertex)
	{
		vertex -= position;
	}
}
