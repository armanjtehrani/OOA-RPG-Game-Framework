#ifndef RPG_GAME_MANAGEMENT_SYSTEM_H_
#define RPG_GAME_MANAGEMENT_SYSTEM_H_


#include <memory>
#include <vector>

#include "Success.h"
#include "CharacterToGameManagerRequest.h"
#include "GameComponentManager.h"
#include "Character.h"


class Character;
class CharacterToGameManagerRequest;
class GameComponentManager;


class GameManager : public std::enable_shared_from_this<GameManager>
{
	//
private:
	std::vector<std::shared_ptr<Character>>
		gameCharacters;
	std::shared_ptr<GameComponentManager>
		myComponentManager;

public:
	auto pushRequest(std::shared_ptr<CharacterToGameManagerRequest>)
		->void;
	
	auto update()->void;
	
	auto sendRequestToMyComponentManager
	(std::shared_ptr<CharacterToGameManagerRequest>)
		->void;

	auto getCharacters()->std::vector<std::shared_ptr<Character>>;

	auto getCharacter(int)->std::weak_ptr<Character>;

	auto addCharacter(std::shared_ptr<Character>)->Success;

	auto removeCharacter(std::shared_ptr<Character>)->Success;

	auto removeCharacter(int)->Success;

	auto removeAllCharacters()->void;

	auto getComponentManager()->std::weak_ptr<GameComponentManager>;
};

#endif // !RPG_GAME_MANAGEMENT_SYSTEM_H_
