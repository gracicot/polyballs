#include "boxdrawer.h"

#include "angle_helper.h"

void BoxDrawer::Render(sf::RenderTarget& Target) const
{
    glColor4ub(255, 255, 255, 255);
	
	glPushMatrix();
	
	glRotatef(radian_to_degree(_angle),0,0,1);
	glBegin(getDrawMode());
	{
		glVertex2d(_position.x - (_dimensions.x/2), _position.y - (_dimensions.y/2));
		glVertex2d(_position.x + (_dimensions.x/2), _position.y - (_dimensions.y/2));
		glVertex2d(_position.x + (_dimensions.x/2), _position.y + (_dimensions.y/2));
		glVertex2d(_position.x - (_dimensions.x/2), _position.y + (_dimensions.y/2));
	}glEnd();
	
	glPopMatrix();
}

BoxDrawer::~BoxDrawer()
{

}

