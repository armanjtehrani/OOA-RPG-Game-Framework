#include "CharacterToGameManagerRequest.h"


CharacterToGameManagerRequest::CharacterToGameManagerRequest(std::weak_ptr<Character> character)
{
	me = character;
}

CharacterToGameManagerRequest::~CharacterToGameManagerRequest()
{
}

void CharacterToGameManagerRequest::setRequestingCharacterTo(std::weak_ptr<Character> entry_character)
{
	me = entry_character;
}

std::weak_ptr<Character> CharacterToGameManagerRequest::getRequestingCharacter()
{
	return me;
}

void CharacterToGameManagerRequest::setCharacterRequest(std::shared_ptr<CharacterRequest> request)
{
	myRequest = request;
}

std::shared_ptr<CharacterRequest> CharacterToGameManagerRequest::getCharacterRequest()
{
	return myRequest;
}
