#include "ToolSpec.h"

ToolSpec::ToolSpec()
{
	partIAffect = CharacterManagerName::NONE;
}

auto ToolSpec::getCharacterManagerIAffect() -> CharacterManagerName
{
	return partIAffect;
}

auto ToolSpec::setCharacterManagerIAffect(CharacterManagerName char_man) -> void
{
	partIAffect = char_man;
}

auto ToolSpec::getAllSpecs() -> std::unordered_map<std::string, std::string>
{
	return specs;
}

auto ToolSpec::setAllSpecs(std::unordered_map<std::string, std::string> entry_specs) -> void
{
	specs = entry_specs;
}

auto ToolSpec::getSpec(std::string key) -> std::string
{
	return specs[key];
}

auto ToolSpec::setSpec(std::string key, std::string val) -> void
{
	if (specs.find(key) != specs.end())
		specs[key] = val;
	else
		specs.insert({ key, val });
}
