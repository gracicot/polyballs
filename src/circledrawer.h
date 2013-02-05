#ifndef CIRCLEDRAWER_H
#define CIRCLEDRAWER_H

#include <subgine/system.hpp>

#include "drawable.h"

class CircleDrawer : public Drawable, virtual public Traits::Position
{
public:
    CircleDrawer() = default;
    ~CircleDrawer() = default;
    virtual void Render(sf::RenderTarget& Target) const;
	
	double getRadius() const;
	void setRadius(double radius);
	
	sf::Color getColor() const;
	void setColor(sf::Color color);
	
private:
	sf::Color _color;
	double _radius;
};

#endif // CIRCLEDRAWER_H
