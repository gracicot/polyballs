#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <SFML/Graphics.hpp>

#include "viewmanager.h"
#include "contextmanager.h"

class MainWindow : public sf::RenderWindow
{
public:
	void render(ViewManager& vm);
	void handleEvents(ContextManager& cm);
	
};

#endif // MAINWINDOW_H
