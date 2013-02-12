#include "mainwindow.h"
#include "eventmanager.h"
#include "mouseevent.h"

MainWindow::MainWindow(): _viewManager(nullptr), _input(this->GetInput())
{
	this->SetView(_view);
    SetFramerateLimit(61);
    UseVerticalSync(true);
}

MainWindow::~MainWindow()
{

}

void MainWindow::show()
{
	this->Create(sf::VideoMode(1024, 768, 32), "Subgine test", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	_view.SetFromRect(sf::FloatRect(-512, -384, 512, 384));
	this->SetView(_view);
	this->EnableKeyRepeat(false);
}

void MainWindow::render()
{
    _viewManager->render(*this);
}

void MainWindow::setViewManager(ViewManager& viewmanager)
{
    _viewManager = &viewmanager;
}

void MainWindow::redirectEvent()
{
    sf::Event event;

    while(this->GetEvent(event))
    {
        if(event.Type == sf::Event::Closed)
        {
            this->Close();
        }
        else if(event.Type == sf::Event::Resized)
        {
			//_view.SetFromRect(sf::FloatRect(-this->GetWidth()/2, -this->GetHeight()/2, this->GetWidth()/2, this->GetHeight()/2));
				_view.SetFromRect(sf::FloatRect(-512, -384, 512, 384));
		}
        else if(event.Type == sf::Event::MouseButtonPressed)
        {
            EventManager::triggerEvent("mouse", new MouseEvent(MouseEventType::Click, ConvertCoords(_input.GetMouseX(), _input.GetMouseY())));
        }
        else if(event.Type == sf::Event::MouseButtonReleased)
        {
            EventManager::triggerEvent("mouse", new MouseEvent(MouseEventType::Unclick,  ConvertCoords(_input.GetMouseX(), _input.GetMouseY())));
        }
        else if(event.Type == sf::Event::MouseMoved)
        {
            if(_input.IsMouseButtonDown(sf::Mouse::Left))
            {
                EventManager::triggerEvent("mouse", new MouseEvent(MouseEventType::Drag,  ConvertCoords(_input.GetMouseX(), _input.GetMouseY())));
            }
            else
            {
                EventManager::triggerEvent("mouse", new MouseEvent(MouseEventType::Move,  ConvertCoords(_input.GetMouseX(), _input.GetMouseY())));
            }
        }
    }
}
