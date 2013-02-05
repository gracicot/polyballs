#include "box.h"

Box::Box()
{

}

Box::~Box()
{

}

void Box::setDimensions(Vector2 dimensions)
{
    BoxDrawer::setDimensions(dimensions);
	
	_vertex.clear();

    _vertex.push_back(Vector2(_position.x - (_dimensions.x/2), _position.y - (_dimensions.y/2)));
    _vertex.push_back(Vector2(_position.x + (_dimensions.x/2), _position.y - (_dimensions.y/2)));
    _vertex.push_back(Vector2(_position.x + (_dimensions.x/2), _position.y + (_dimensions.y/2)));
    _vertex.push_back(Vector2(_position.x - (_dimensions.x/2), _position.y + (_dimensions.y/2)));
}
