#include "circledrawer.h"

void CircleDrawer::Render(sf::RenderTarget& Target) const
{
    glColor4ub(_color.r, _color.g, _color.b, _color.a);
    
	glPushMatrix();
	glTranslatef(_position.x, _position.y, 0);
	
	glBegin(getDrawMode());
    {
        double angle;
        for(int i=0 ; i<int(sqrt(_radius*15)) ; i++)
        {
			angle = 2 * pi * i / int(sqrt(_radius*10));
            glVertex2d((cos(angle) * _radius), (sin(angle) * _radius));
        }
    }
    glEnd();
	
	glPopMatrix();
}

sf::Color CircleDrawer::getColor() const
{
	return _color;
}

double CircleDrawer::getRadius() const
{
	return _radius;
}

void CircleDrawer::setColor(sf::Color color)
{
	_color = color;
}

void CircleDrawer::setRadius(double radius)
{
	_radius = radius;
}

