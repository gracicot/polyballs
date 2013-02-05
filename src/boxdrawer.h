#ifndef BOXDRAWER_H
#define BOXDRAWER_H

#include "drawable.h"
#include <subgine/system.hpp>


class BoxDrawer : public Drawable, public virtual Traits::Position, public virtual Traits::Angle
{
    BoxDrawer() = default;
    virtual ~BoxDrawer();
	
    virtual void Render(sf::RenderTarget& Target) const;
	
private:
	Vector2 _dimensions;
};

#endif // BOXDRAWER_H
