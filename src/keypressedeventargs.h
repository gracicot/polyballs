#ifndef KEYPRESSEDEVENTARGS_H
#define KEYPRESSEDEVENTARGS_H

#include "eventargs.h"
#include <SFML/Window/Event.hpp>

class KeyPressedEventArgs : public EventArgs
{

public:
    KeyPressedEventArgs(const sf::Key::Code key);
    virtual ~KeyPressedEventArgs();
	
	sf::Key::Code getKey() const;
	void setKey(const sf::Key::Code key);
	
private:
	sf::Key::Code _key;
};

#endif // KEYPRESSEDEVENTARGS_H
