#include "CharacterManager.h"



CharacterManager::CharacterManager()
{
}


CharacterManager::~CharacterManager()
{
}

auto CharacterManager::hasManager(CharacterManagerName manager_name) const -> bool
{
	if (myManagers.find(manager_name) != myManagers.end())
		return true;
	else
		return false;
}

auto CharacterManager::getManager(CharacterManagerName manager_name) const -> std::weak_ptr<CharacterManagementSystem>
{
	return myManagers.find(manager_name)->second;
}