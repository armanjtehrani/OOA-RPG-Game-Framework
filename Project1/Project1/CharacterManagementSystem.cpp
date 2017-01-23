#include "CharacterManagementSystem.h"

CharacterManagementSystem::CharacterManagementSystem()
{
	myName = CharacterManagerName::NONE;
}

auto CharacterManagementSystem::getMyName() -> CharacterManagerName
{
	return myName;
}

auto CharacterManagementSystem::useTool(std::shared_ptr<ToolSpec> new_spec) -> void
{
	addToolSpecToMyToolSpecs(new_spec);
	addSpecToMe(new_spec);
}

auto CharacterManagementSystem::unuseTool(std::shared_ptr<ToolSpec>old_spec) -> Success
{
	Success is_succeeded = removeToolSpecFromMyToolSpecs(old_spec);
	if (is_succeeded == Success::SUCCEEDED) {
		removeSpecFromMe(old_spec);
		return Success::SUCCEEDED;
	}
	else
		return Success::FAILED;
}

auto CharacterManagementSystem::addToolSpecToMyToolSpecs(std::shared_ptr<ToolSpec> new_spec) -> void
{
	myToolSpecs.push_back(new_spec);
}

auto CharacterManagementSystem::removeToolSpecFromMyToolSpecs(std::shared_ptr<ToolSpec>old_spec) -> Success
{
	Success T = Success::FAILED;
	for (int i = 0;i < myToolSpecs.size();i++)
	{
		if (*myToolSpecs[i] == *old_spec) 
		{
			T = Success::SUCCEEDED;
			myToolSpecs.erase(myToolSpecs.begin() + i);//i's place
		}
	}
	return T;
}
