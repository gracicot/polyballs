#ifndef KEYPRESSEDEVENTARGS_H
#define KEYPRESSEDEVENTARGS_H

#include "eventargs.h"

class KeyPressedEventArgs : public EventArgs
{

public:
    KeyPressedEventArgs(const char key='\0');
    virtual ~KeyPressedEventArgs();
	
	char getKey() const;
	void setKey(const char key);
	
private:
	char _key;
};

#endif // KEYPRESSEDEVENTARGS_H
