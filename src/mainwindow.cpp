#include "mainwindow.h"
#include "eventmanager.h"
#include "mouseevent.h"
#include "keypressedeventargs.h"

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
	this->Create(sf::VideoMode(1366, 900, 32), "Subgine test", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	_view.SetFromRect(sf::FloatRect(-1.0 * this->GetWidth() / 2.0, -1.0 * this->GetHeight() / 2.0, this->GetWidth() / 2.0, this->GetHeight() / 2.0));
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
	//sf::Lock lock(MainEngine::mutex());

	sf::Event event;

	while(this->GetEvent(event))
	{
		if(event.Type == sf::Event::Closed)
		{
			this->Close();
		}
		else if(event.Type == sf::Event::Resized)
		{
			_view.SetFromRect(sf::FloatRect(-1.0 * this->GetWidth() / 2.0, -1.0 * this->GetHeight() / 2.0, this->GetWidth() / 2.0, this->GetHeight() / 2.0));
		}
		else if(event.Type == sf::Event::MouseButtonPressed)
		{
			MouseEvent* myEvent = nullptr;
			myEvent = new MouseEvent(MouseEventType::Click, Vector2(_input.GetMouseX() - this->GetWidth() / 2.0, _input.GetMouseY() - this->GetHeight() / 2.0));
			EventManager::triggerEvent("mouse", myEvent);
		}
		else if(event.Type == sf::Event::MouseButtonReleased)
		{

			MouseEvent* myEvent = nullptr;
			myEvent = new MouseEvent(MouseEventType::Unclick, Vector2(_input.GetMouseX() - this->GetWidth() / 2.0, _input.GetMouseY() - this->GetHeight() / 2.0));
			EventManager::triggerEvent("mouse", myEvent);

		}
		else if(event.Type == sf::Event::MouseMoved)
		{
			if(_input.IsMouseButtonDown(sf::Mouse::Left))
			{
				MouseEvent* myEvent = nullptr;
				myEvent = new MouseEvent(MouseEventType::Drag, Vector2(_input.GetMouseX() - this->GetWidth() / 2.0, _input.GetMouseY() - this->GetHeight() / 2.0));
				EventManager::triggerEvent("mouse", myEvent);
			}
			else
			{
				MouseEvent* myEvent = nullptr;
				myEvent = new MouseEvent(MouseEventType::Move, Vector2(_input.GetMouseX() - this->GetWidth() / 2.0, _input.GetMouseY() - this->GetHeight() / 2.0));
				EventManager::triggerEvent("mouse", myEvent);
			}
		}
		else if(event.Type == sf::Event::KeyPressed)
		{
			KeyPressedEventArgs* myEvent = nullptr;
			myEvent = new KeyPressedEventArgs(event.Key.Code);
			EventManager::triggerEvent("keyPressed", myEvent);
		}
	}

}



