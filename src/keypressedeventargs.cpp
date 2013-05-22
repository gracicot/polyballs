#include "keypressedeventargs.h"

KeyPressedEventArgs::KeyPressedEventArgs(const sf::Keyboard::Key key): _key(key)
{
	
}

KeyPressedEventArgs::~KeyPressedEventArgs()
{

}

sf::Keyboard::Key KeyPressedEventArgs::getKey() const
{
	return _key;
}

void KeyPressedEventArgs::setKey(const sf::Keyboard::Key key)
{
	_key = key;
}
