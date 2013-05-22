#ifndef KEYPRESSEDEVENTARGS_H
#define KEYPRESSEDEVENTARGS_H

#include "eventargs.h"
#include <SFML/Window/Event.hpp>

class KeyPressedEventArgs : public EventArgs
{

public:
    KeyPressedEventArgs(const sf::Keyboard::Key key);
    virtual ~KeyPressedEventArgs();
	
	sf::Keyboard::Key getKey() const;
	void setKey(const sf::Keyboard::Key key);
	
private:
	sf::Keyboard::Key _key;
};

#endif // KEYPRESSEDEVENTARGS_H
