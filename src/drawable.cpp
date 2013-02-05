#include "drawable.h"

Drawable::Drawable()
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
