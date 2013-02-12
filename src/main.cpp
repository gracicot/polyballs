#include <subgine/system.hpp>
#include <subgine/physic.hpp>
#include <subgine/collision.hpp>

#include "mainwindow.h"
#include "circlesboxviewmanager.h"
#include "circlesboxcontextmanager.h"
#include "box.h"
#include "circleobject.h"

int main(int argc, char **argv)
{
    MainWindow myWindow;
	CirclesBoxViewManager viewManager;
	CirclesBoxContextManager contextManager;
	
	myWindow.setViewManager(viewManager);
	contextManager.setViewManager(viewManager);	
	
	myWindow.show();
	
	while (myWindow.IsOpened())
    {
		myWindow.redirectEvent();
        // Clear the screen (fill it with black color)
        myWindow.Clear();
		myWindow.render();
		
        // Display window contents on screen
        myWindow.Display();
    }
	
    return 0;
}
