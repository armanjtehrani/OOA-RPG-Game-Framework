#ifndef RPG_CHARACTER_TO_GAME_MANAGER_REQUEST_H_
#define RPG_CHARACTER_TO_GAME_MANAGER_REQUEST_H_


#include <memory>


#include "Character.h"
#include "CharacterRequest.h"

class Character;

class CharacterToGameManagerRequest
{
	//attributes
private:
	std::weak_ptr<Character> me;
	std::shared_ptr<CharacterRequest> myRequest;


	//constructor - destructor
public:
	CharacterToGameManagerRequest(std::weak_ptr<Character>);
	~CharacterToGameManagerRequest();


	//
	void setRequestingCharacterTo(std::weak_ptr<Character>);
	std::weak_ptr<Character> getRequestingCharacter();
	void setCharacterRequest(std::shared_ptr<CharacterRequest>);
	std::shared_ptr<CharacterRequest> getCharacterRequest();
};


#endif // !RPG_CHARACTER_TO_GAME_MANAGER_REQUEST_H_