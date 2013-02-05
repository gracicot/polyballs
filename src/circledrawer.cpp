#include "circledrawer.h"

void CircleDrawer::Render(sf::RenderTarget& Target) const
{
    glColor4ub(_color.r, _color.g, _color.b, _color.a);
    glBegin(getDrawMode());
    {
        double angle;
        for(int i=0 ; i<int(_radius/2) ; i++)
        {
			angle = 2 * pi * i / int(_radius/2);
            glVertex2d(_position.x + (cos(angle) * _radius), _position.y + (sin(angle) * _radius));
        }
    }
    glEnd();
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

