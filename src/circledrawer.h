#ifndef CIRCLEDRAWER_H
#define CIRCLEDRAWER_H

#include <subgine/system.hpp>

#include "drawable.h"

class CircleDrawer : public Drawable, virtual public Traits::Position, public virtual Traits::Radius
{
public:
    CircleDrawer() = default;
    ~CircleDrawer() = default;
    virtual void Render(sf::RenderTarget& Target) const;

	
	sf::Color getColor() const;
	void setColor(sf::Color color);
	
private:
	sf::Color _color;
};

#endif // CIRCLEDRAWER_H
