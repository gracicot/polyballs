#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <SFML/Graphics.hpp>

#include "viewmanager.h"
#include "contextmanager.h"

class MainWindow : public sf::RenderWindow
{
public:
    MainWindow();
    virtual ~MainWindow();
	
	void render();
	
	void setViewManager(ViewManager& viewmanager);
	
private:
	ViewManager* _viewManager;
	
};

#endif // MAINWINDOW_H
