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
	return myManagers.at(manager_name);
}

auto CharacterManager::getAllManagers() const 
-> std::unordered_map<CharacterManagerName,
	std::weak_ptr<CharacterManagementSystem>>
{
	std::unordered_map<CharacterManagerName,
		std::weak_ptr<CharacterManagementSystem>> ret_managers;
	for (auto manager : myManagers)
		ret_managers.insert(manager);

	return ret_managers;

}

auto CharacterManager::addManager(std::weak_ptr<CharacterManagementSystem>new_manager) -> Success
{
	auto manager = new_manager.lock();
	if (myManagers.find(manager->getMyName()) == myManagers.end())
	{
		myManagers.insert({ manager->getMyName(), manager });
		return Success::SUCCEEDED;
	}
	return Success::FAILED;
}

auto CharacterManager::deleteManager(CharacterManagerName old_manager_name) -> Success
{
	auto old_manager_place = myManagers.find(old_manager_name);

	if (old_manager_place == myManagers.end())
		return Success::FAILED;

	myManagers.erase(old_manager_place);
	return Success::SUCCEEDED;
}

auto CharacterManager::clearAllManagers() -> void
{
	myManagers.clear();
}
