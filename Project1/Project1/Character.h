#ifndef RPG_CHARACTER_H_
#define RPG_CHARACTER_H_

#include <memory>

#include "Success.h"

#include "GameManager.h"
#include "HandlerName.h"


#include "CharacterRequest.h"
#include "CharacterToGameManagerRequest.h"

#include "CharacterManager.h"
#include "CharacterBlockingSystem.h"


class CharacterToGameManagerRequest;
class GameManager;

class Character : public std::enable_shared_from_this<Character>
{
	//attributes
private:
	std::unique_ptr<CharacterBlockingSystem> myBlockingSystem;
	std::shared_ptr<CharacterManager> myManager;
	std::weak_ptr<GameManager> mainGameManager;


	//constructor - destructor
public:
	Character();
	~Character();

	//game manager
	auto setMainGameManager(std::weak_ptr<GameManager>)->void;
	auto getMainGameManager()->std::weak_ptr<GameManager>;

	//blocking system
public:
	auto isBlocked()->bool;
	auto whoBlockedMe()->HandlerName;
	auto blockAs(HandlerName)->void;
	auto unblock()->void;

	//character manager
public:
	auto getManager()->std::weak_ptr<CharacterManager>;

	//requests
public:
	auto setRequest(std::shared_ptr<CharacterRequest>)->Success;
private:
	auto packRequest(std::shared_ptr<CharacterRequest>)->std::shared_ptr<CharacterToGameManagerRequest>;
	auto sendRequestToGameManager(std::shared_ptr<CharacterToGameManagerRequest>)->Success;
};

#endif // !RPG_CHARACTER_H_