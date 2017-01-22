#pragma once
#include "CharacterBlockingSystem.h"
#include "HandlerName.h"

class BasicCharacterBlockingSystem : public CharacterBlockingSystem
{
	//attributes
private:
	bool blocked;
	HandlerName whoBlocked;


	//constructor-destructor
public:
	BasicCharacterBlockingSystem();
	~BasicCharacterBlockingSystem();

	//blocking system
	virtual auto isBlocked()->bool override;
	virtual auto whoBlockedMe()->HandlerName override;
	virtual auto blockAs(HandlerName)->bool override;
	virtual auto unblock()->void override;
};

