#ifndef RPG_CHARACTER_REQUEST_H_
#define RPG_CHARACTER_REQUEST_H_


#include "HandlerName.h"
#include "CharacterRequestType.h"


class CharacterRequest
{
protected:
	virtual auto setRequestReceiver(HandlerName)->void = 0;
	virtual auto setRequestType(CharacterRequestType)->void = 0;
	
public:
	virtual auto getRequestReceiver()->HandlerName = 0;
	virtual auto getRequestType()->CharacterRequestType = 0;
};



#endif // !RPG_CHARACTER_REQUEST_H_
