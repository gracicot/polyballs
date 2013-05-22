#include "mainwindow.h"
#include "eventmanager.h"
#include "mouseevent.h"
#include "keypressedeventargs.h"

MainWindow::MainWindow(): _viewManager(nullptr)
{
	glEnable(GL_TEXTURE_2D);
	this->setView(_view);
	this->setVerticalSyncEnabled(true);
}

MainWindow::~MainWindow()
{

}

void MainWindow::show()
{
	this->create(sf::VideoMode(1366, 900, 32), "Subgine test", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	_view.reset(sf::FloatRect(-0.5 * this->getSize().x, -0.5 * this->getSize().y, this->getSize().x / 2.0, this->getSize().y / 2.0));
	this->setView(_view);
	this->setKeyRepeatEnabled(false);
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

	while(this->pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
		{
			this->close();
		}
		else if(event.type == sf::Event::Resized)
		{
			_view.reset(sf::FloatRect(-1.0 * this->getSize().x / 2.0, -1.0 * this->getSize().y / 2.0, this->getSize().x / 2.0, this->getSize().y / 2.0));
		}
		else if(event.type == sf::Event::MouseButtonPressed)
		{
			MouseEvent* myEvent = nullptr;
			myEvent = new MouseEvent(MouseEventType::Click, Vector2(event.mouseButton.x - this->getSize().x / 2.0, event.mouseButton.y - this->getSize().y / 2.0));
			EventManager::triggerEvent("mouse", myEvent);
		}
		else if(event.type == sf::Event::MouseButtonReleased)
		{

			MouseEvent* myEvent = nullptr;
			myEvent = new MouseEvent(MouseEventType::Unclick, Vector2(event.mouseButton.x - this->getSize().x / 2.0, event.mouseButton.y - this->getSize().y / 2.0));
			EventManager::triggerEvent("mouse", myEvent);

		}
		else if(event.type == sf::Event::MouseMoved)
		{
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				MouseEvent* myEvent = nullptr;
				myEvent = new MouseEvent(MouseEventType::Drag, Vector2(event.mouseButton.x - this->getSize().x / 2.0, event.mouseButton.y - this->getSize().y / 2.0));
				EventManager::triggerEvent("mouse", myEvent);
			}
			else
			{
				MouseEvent* myEvent = nullptr;
				myEvent = new MouseEvent(MouseEventType::Move, Vector2(event.mouseButton.x - this->getSize().x / 2.0, event.mouseButton.y - this->getSize().y / 2.0));
				EventManager::triggerEvent("mouse", myEvent);
			}
		}
		else if(event.type == sf::Event::KeyPressed)
		{
			KeyPressedEventArgs* myEvent = nullptr;
			myEvent = new KeyPressedEventArgs(event.key.code);
			EventManager::triggerEvent("keyPressed", myEvent);
		}
	}

}



