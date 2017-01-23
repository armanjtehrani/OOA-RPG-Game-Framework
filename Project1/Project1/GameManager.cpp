#include "GameManager.h"

auto GameManager::pushRequest(std::shared_ptr<CharacterToGameManagerRequest>character_request) -> void
{
	sendRequestToMyComponentManager(character_request);
}

auto GameManager::update() -> void
{
	myComponentManager->done();
}

auto GameManager::sendRequestToMyComponentManager(std::shared_ptr<CharacterToCMRequest>character_request) -> void
{
	myComponentManager->addCharacterToCMRequest(character_request);
}

auto GameManager::getCharacters() -> std::vector<std::shared_ptr<Character>>
{
	return gameCharacters;
}

auto GameManager::getCharacter(int index) -> std::weak_ptr<Character>
{
	if (index >= 0 && index < gameCharacters.size())
		return gameCharacters[index];
	else
		return std::weak_ptr<Character>();

	
}

auto GameManager::addCharacter(std::shared_ptr<Character>new_character) -> Success
{
	for(auto game_character :gameCharacters)
	{
		if (game_character == new_character)
			return Success::FAILED;
	}
	gameCharacters.push_back(new_character);
	new_character->setMainGameManager(shared_from_this());

	return Success::SUCCEEDED;
}

auto GameManager::removeCharacter(std::shared_ptr<Character>old_character) -> Success
{
	for (auto i = gameCharacters.begin(); i < gameCharacters.end(); i++)
	{
		if (*i == old_character)
		{
			gameCharacters.erase(i);
			return Success::SUCCEEDED;
		}
	}

	return Success::FAILED;
}

auto GameManager::removeCharacter(int index) -> Success
{
	if (0 <= index && index < gameCharacters.size())
	{
		gameCharacters.erase(gameCharacters.begin() + index);
		return Success::SUCCEEDED;
	}
	else
		return Success::FAILED;
}

auto GameManager::removeAllCharacters() -> void
{
	gameCharacters.clear();
}

auto GameManager::getComponentManager() -> std::weak_ptr<GameComponentManager>
{
	return myComponentManager;
}
