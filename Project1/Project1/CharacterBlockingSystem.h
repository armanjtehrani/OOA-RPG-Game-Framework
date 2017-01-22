#ifndef RPG_CHARACTER_BLOCKING_SYSTEM_H_
#define RPG_CHARACTER_BLOCKING_SYSTEM_H_


#include "HandlerName.h"

class CharacterBlockingSystem
{
public:
	virtual auto isBlocked()->bool = 0;
	virtual auto whoBlockedMe()->HandlerName = 0;
	virtual auto blockAs(HandlerName)->bool = 0;
	virtual auto unblock()->void = 0;
};


#endif // !RPG_CHARACTER_BLOCKING_SYSTEM_H_
