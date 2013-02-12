#include "keypressedeventargs.h"

KeyPressedEventArgs::KeyPressedEventArgs(const char key): _key(key)
{
	
}

KeyPressedEventArgs::~KeyPressedEventArgs()
{

}

char KeyPressedEventArgs::getKey() const
{
	return _key;
}

void KeyPressedEventArgs::setKey(const char key)
{
	_key = key;
}
