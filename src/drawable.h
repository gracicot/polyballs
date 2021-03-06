#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML/Graphics.hpp>
#include <GL/gl.h>

class Drawable : public sf::Drawable
{
public:
    Drawable();
	GLenum getDrawMode() const;
	void setDrawMode(const GLenum drawMode);
	
private:
	GLenum _drawMode;
};

#endif // DRAWABLE_H
