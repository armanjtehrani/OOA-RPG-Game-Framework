#include "Tool.h"

auto Tool::addSpec(ToolSpec new_spec) -> Success
{
	for (auto spec : mySpecs)
		if (spec == new_spec)
			return Success::FAILED;
	mySpecs.push_back(new_spec);
	return Success::SUCCEEDED;
}

auto Tool::removeSpec(ToolSpec old_spec) -> Success
{
	for (int i = 0; i < mySpecs.size(); i++)
	{
		if (mySpecs[i] == old_spec)
		{
			mySpecs.erase(mySpecs.begin() + i);
			return Success::SUCCEEDED;
		}
	}
	return Success::FAILED;
}

auto Tool::getSpecs(CharacterManagerName affected) const -> std::vector<ToolSpec>
{
	std::vector<ToolSpec> specs;
	for (auto spec : mySpecs)
		if (spec.getCharacterManagerIAffect() == affected)
			specs.push_back(spec);
	return specs;
}

auto Tool::getAllSpecs() const -> const std::vector<ToolSpec>&
{
	return mySpecs;
}
