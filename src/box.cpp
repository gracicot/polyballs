#include "box.h"

Box::Box()
{
	_collisionSquares.push_back(new CollisionSquare);
	_collisionSquares.push_back(new CollisionSquare);
	_collisionSquares.push_back(new CollisionSquare);
	_collisionSquares.push_back(new CollisionSquare);
}

Box::~Box()
{
	for(auto square : _collisionSquares)
	{
		delete square;
	}
}

void Box::setDimensions(Vector2 dimensions)
{
    BoxDrawer::setDimensions(dimensions);
	
	_vertex.clear();
	
	double thickness = 900;

    _vertex.push_back(Vector2(_position.x - (_dimensions.x/2), _position.y - (_dimensions.y/2)));
    _vertex.push_back(Vector2(_position.x + (_dimensions.x/2), _position.y - (_dimensions.y/2)));
    _vertex.push_back(Vector2(_position.x + (_dimensions.x/2), _position.y + (_dimensions.y/2)));
    _vertex.push_back(Vector2(_position.x - (_dimensions.x/2), _position.y + (_dimensions.y/2)));
	
 	_collisionSquares[0]->setPosition(Vector2(_position.x, (_position.y-(thickness/2)) - (_dimensions.y/2)));
	_collisionSquares[0]->setDimensions(Vector2(_dimensions.x+(thickness*2), thickness));
 	_collisionSquares[0]->setPosition(Vector2());
	
 	_collisionSquares[1]->setPosition(Vector2(_position.x + (_dimensions.x/2) + (thickness/2), _position.y));
	_collisionSquares[1]->setDimensions(Vector2(thickness, _dimensions.y+(thickness*2)));
 	_collisionSquares[1]->setPosition(Vector2());
	
 	_collisionSquares[2]->setPosition(Vector2(_position.x, _position.y + (thickness/2) + (_dimensions.y/2)));
	_collisionSquares[2]->setDimensions(Vector2(_dimensions.x+(thickness*2), thickness));
 	_collisionSquares[2]->setPosition(Vector2());
	
 	_collisionSquares[3]->setPosition(Vector2((_position.x-(thickness/2)) - (_dimensions.x/2), _position.y));
	_collisionSquares[3]->setDimensions(Vector2(thickness, _dimensions.y+(thickness*2)));
 	_collisionSquares[3]->setPosition(Vector2());
}

void Box::setPosition(Vector2 position)
{
	_position = position;
}

double Box::getAngle() const
{
    return _angle;
}

void Box::setAngle(double angle)
{
	Vector2 square_pos;
	_angle = angle;
	for(auto square : _collisionSquares)
	{
		square->setAngle(angle);
// 		square_pos = square->getPosition();
		
		
// 		square->setPosition(square_pos);
	}
}

std::vector< CollisionSquare* >& Box::collisionsSquares()
{
	return _collisionSquares;
}

const std::vector< CollisionSquare* >& Box::collisionsSquares() const
{
	return _collisionSquares;
}
