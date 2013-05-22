#ifndef BOXDRAWER_H
#define BOXDRAWER_H

#include <subgine/system.hpp>
#include "drawable.h"

class BoxDrawer : public Drawable, public virtual Traits::Position, public virtual Traits::Angle
{
public:
    BoxDrawer() = default;
    virtual ~BoxDrawer();
	
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	virtual void setDimensions(Vector2 dimensions);
	Vector2 getDimensions() const;
	
protected:
	Vector2 _dimensions;
};

#endif // BOXDRAWER_H
