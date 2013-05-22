#include "circledrawer.h"

void CircleDrawer::draw(sf::RenderTarget& Target, sf::RenderStates states) const
{
    int num_segments = int(sqrt(_radius*24));

    float theta = 2 * pi / float(num_segments);
    float cosine = cos(theta);
    float sine = sin(theta);

    Vector2 verticle(_radius, 0);
	
    glColor4ub(_color.r, _color.g, _color.b, _color.a);

    glPushMatrix();
    glTranslatef(_position.x, _position.y, 0);

    glBegin(getDrawMode());
    {
		float temp;
        for(int i = 0; i < num_segments; i++)
        {
            glVertex2d(verticle.x, verticle.y);

            temp = verticle.x;
            verticle.x = cosine * verticle.x - sine * verticle.y;
            verticle.y = sine * temp + cosine * verticle.y;
        }
    }
    glEnd();

    glPopMatrix();
}

sf::Color CircleDrawer::getColor() const
{
    return _color;
}

void CircleDrawer::setColor(sf::Color color)
{
    _color = color;
}
