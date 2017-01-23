#include "Character.h"
#include "BasicCharacterBlockingSystem.h"


Character::Character()
{
	myBlockingSystem = std::make_unique<BasicCharacterBlockingSystem>();
	myManager = std::make_shared<CharacterManager>();
	mainGameManager = std::weak_ptr<GameManager>();
}


Character::~Character()
{
}

auto Character::setMainGameManager(std::weak_ptr<GameManager>new_game_manager) -> void
{
	mainGameManager = new_game_manager.lock();
}

auto Character::getMainGameManager() -> std::weak_ptr<GameManager>
{
	return mainGameManager;
}


auto Character::isBlocked()->bool
{
	return myBlockingSystem->isBlocked();
}

auto Character::whoBlockedMe()->HandlerName
{
	return myBlockingSystem->whoBlockedMe();
}

auto Character::blockAs(HandlerName blocker)->void
{
	myBlockingSystem->blockAs(blocker);
}

auto Character::unblock()->void
{
	myBlockingSystem->unblock();
}

auto Character::getManager()->std::weak_ptr<CharacterManager>
{
	return myManager;
}

auto Character::setRequest(std::shared_ptr<CharacterRequest>req) -> Success
{
	auto to_game_req = packRequest(req);
	if (sendRequestToGameManager(to_game_req) == Success::SUCCEEDED)
		return Success::SUCCEEDED;
	else
		return Success::FAILED;
}

auto Character::packRequest(std::shared_ptr<CharacterRequest>character_req) -> std::shared_ptr<CharacterToGameManagerRequest>
{
	auto req_to_game = std::make_shared<CharacterToGameManagerRequest>(shared_from_this());
	req_to_game->setCharacterRequest(character_req);

	return req_to_game;
}

auto Character::sendRequestToGameManager(std::shared_ptr<CharacterToGameManagerRequest>req) -> Success
{
	if (!mainGameManager.expired())
	{
		mainGameManager.lock()->pushRequest(req);
		return Success::SUCCEEDED;
	}
	return Success::FAILED;
}
