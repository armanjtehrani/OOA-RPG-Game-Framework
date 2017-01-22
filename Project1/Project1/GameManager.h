#ifndef RPG_GAME_MANAGEMENT_SYSTEM_H_
#define RPG_GAME_MANAGEMENT_SYSTEM_H_


#include <memory>


#include "CharacterToGameManagerRequest.h"


class CharacterToGameManagerRequest;

class GameManager : public std::enable_shared_from_this<GameManager>
{
public:
	auto pushRequest(std::shared_ptr<CharacterToGameManagerRequest>)
		->void;
};

#endif // !RPG_GAME_MANAGEMENT_SYSTEM_H_
