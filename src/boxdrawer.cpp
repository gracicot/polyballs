#include "boxdrawer.h"

#include "angle_helper.h"

void BoxDrawer::Render(sf::RenderTarget& Target) const
{
    glColor4ub(255, 255, 255, 255);
	
	glPushMatrix();
	
	glTranslatef(_position.x, _position.y, 0);
	glRotatef(radian_to_degree(_angle),0,0,1);
	glBegin(getDrawMode());
	{
		glVertex2d(-_dimensions.x/2, -_dimensions.y/2);
		glVertex2d(_dimensions.x/2, -_dimensions.y/2);
		glVertex2d(_dimensions.x/2,_dimensions.y/2);
		glVertex2d(-_dimensions.x/2, _dimensions.y/2);
	}glEnd();
	
	glPopMatrix();
}

BoxDrawer::~BoxDrawer()
{

}

Vector2 BoxDrawer::getDimensions() const
{
	return _dimensions;
}

void BoxDrawer::setDimensions(Vector2 dimensions)
{
	_dimensions = dimensions;
}


