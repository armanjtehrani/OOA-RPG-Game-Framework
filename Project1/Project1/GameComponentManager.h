#ifndef RPG_GAME_COMPONENT_MANAGER_H_
#define RPG_GAME_COMPONENT_MANAGER_H_


#include "CharacterToGameManagerRequest.h"



class CharacterToGameManagerRequest;

using CharacterToCMRequest
= CharacterToGameManagerRequest;

class GameComponentManager
{
	

public:
	GameComponentManager();
	~GameComponentManager();


	auto addCharacterToCMRequest
	(std::shared_ptr<CharacterToCMRequest>)->void{}

	auto done()->void{}
};

#endif // !RPG_GAME_COMPONENT_MANAGER_H_