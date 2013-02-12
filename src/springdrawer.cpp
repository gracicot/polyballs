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


#include "springdrawer.h"

#include <subgine/system.hpp>

#include <cmath>

SpringDrawer::SpringDrawer(const Rule::Spring& spring, const PhysicPoint& object, float size) : _spring(spring), _object(object), _size(size)
{

}

SpringDrawer::SpringDrawer(const SpringDrawer& c) : _spring(c._spring), _object(c._object), _size(c._size)
{

}

SpringDrawer::~SpringDrawer()
{

}

float SpringDrawer::getSize()
{
	return _size;
}

void SpringDrawer::setSize(float size)
{
	_size = size > 0 ? size : 0;
}

void SpringDrawer::Render(sf::RenderTarget& target) const
{
	const Vector2 point = _object.getPosition();

	if(_spring.getSize() > 0 && (_spring.getValue().x > 0 || _spring.getValue().y > 0) && _size > 0)
	{
		glBegin(GL_LINE_STRIP);
		{
			double stretch = (_spring.getPosition() - point).getLenght() / _spring.getSize();


			glColor3ub(128, 128, 128);


			Vector2 position = _spring.getPosition();
			
			Vector2 odd_nodes = point - _spring.getPosition();
			Vector2 even_nodes = point - _spring.getPosition();
			
			odd_nodes.setAngle(odd_nodes.getAngle() + pi/2);
			even_nodes.setAngle(even_nodes.getAngle() - pi/2);
			
			odd_nodes = odd_nodes.unit() * _spring.getValue() * _size;
			even_nodes = even_nodes.unit() * _spring.getValue() * _size;
			
			for(int i = 0 ; i <= _spring.getSize() / 4 ; i++)
			{
				if(i == 0 || i == _spring.getSize() / 4)
				{
					glVertex2d(position.x, position.y);
				}
				else if(i % 2 == 0)
				{
					glVertex2d(even_nodes.x + position.x, even_nodes.y + position.y);
				}
				else
				{
					glVertex2d(odd_nodes.x + position.x, odd_nodes.y + position.y);
				}

				position += (point - _spring.getPosition()) / (_spring.getSize() / 4);
			}
		}
		glEnd();
	}
}

// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
