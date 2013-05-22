/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2012  Guillaume <email>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SPRINGDRAWER_H
#define SPRINGDRAWER_H

#include <subgine/physic.hpp>

#include "drawable.h"

class SpringDrawer : public Drawable
{

public:
	SpringDrawer(const Rule::Spring& spring, const PhysicPoint& object, float size);
	SpringDrawer(const SpringDrawer& c);
	virtual ~SpringDrawer();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	float getSize();
	void setSize(float size);
	
	const PhysicPoint& getObject() const;

private:
	float _size;
	const Rule::Spring& _spring;
	const PhysicPoint& _object;
};

#endif // SPRINGDRAWER_H
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4;
