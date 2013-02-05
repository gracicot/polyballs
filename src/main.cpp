#include <subgine/system.hpp>
#include <subgine/physic.hpp>
#include <subgine/collision.hpp>

#include "mainwindow.h"

int main(int argc, char **argv)
{
    MainWindow myWindow;
	
	while (myWindow.IsOpened())
    {
        // Process events
        sf::Event Event;
        while (myWindow.GetEvent(Event))
        {
            // Close window : exit
            if (Event.Type == sf::Event::Closed)
                myWindow.Close();
        }

        // Clear the screen (fill it with black color)
        myWindow.Clear();

        // Display window contents on screen
        myWindow.Display();
    }
	
    return 0;
}
