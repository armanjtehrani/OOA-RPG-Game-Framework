#ifndef RPG_CHARACTER_MANAGER_H_
#define RPG_CHARACTER_MANAGER_H_


#include <unordered_map>
#include <memory>

#include "CharacterManagerName.h"
#include "CharacterManagementSystem.h"

class CharacterManager
{
	//attributes
private:
	std::unordered_map<CharacterManagerName,
		std::shared_ptr<CharacterManagementSystem>>
		myManagers;


	//constructor - destructor
public:
	CharacterManager();
	~CharacterManager();
	
	//
	auto hasManager(CharacterManager) const->bool;

	auto getManager(CharacterManagerName) const->std::weak_ptr<CharacterManagementSystem>;

	auto getAllManagers() const->std::unordered_map<CharacterManagerName, std::weak_ptr<CharacterManagementSystem>>;
};

#endif // !RPG_CHARACTER_MANAGER_H_