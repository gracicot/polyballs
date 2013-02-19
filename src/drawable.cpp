#include "drawable.h"

Drawable::Drawable() : _drawMode(GL_LINE_LOOP)
{
	
}

GLenum Drawable::getDrawMode() const
{
	return _drawMode;
}

void Drawable::setDrawMode(const GLenum drawMode)
{
	_drawMode = drawMode;
}
