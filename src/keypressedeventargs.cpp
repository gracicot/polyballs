#include "keypressedeventargs.h"

KeyPressedEventArgs::KeyPressedEventArgs(const sf::Key::Code key): _key(key)
{
	
}

KeyPressedEventArgs::~KeyPressedEventArgs()
{

}

sf::Key::Code KeyPressedEventArgs::getKey() const
{
	return _key;
}

void KeyPressedEventArgs::setKey(const sf::Key::Code key)
{
	_key = key;
}
