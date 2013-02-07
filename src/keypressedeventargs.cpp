#include "keypressedeventargs.h"

KeyPressedEventArgs::KeyPressedEventArgs(char key): _key(key)
{
	
}

KeyPressedEventArgs::~KeyPressedEventArgs()
{

}

char KeyPressedEventArgs::getKey() const
{
	return _key;
}

void KeyPressedEventArgs::setKey(char key)
{
	_key = key;
}
