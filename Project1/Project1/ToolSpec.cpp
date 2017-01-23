#include "ToolSpec.h"


ToolSpec::ToolSpec()
{
	partIAffect = CharacterManagerName::NONE;
}

auto ToolSpec::getCharacterManagerIAffect() const-> CharacterManagerName
{
	return partIAffect;
}

auto ToolSpec::setCharacterManagerIAffect(CharacterManagerName char_man) -> void
{
	partIAffect = char_man;
}

auto ToolSpec::getAllSpecs() const-> const std::unordered_map<std::string, std::string>&
{
	return specs;
}

auto ToolSpec::setAllSpecs(std::unordered_map<std::string, std::string> entry_specs) -> void
{
	specs = entry_specs;
}

auto ToolSpec::getSpec(std::string key) const-> std::string
{
	return specs.at(key);
}

auto ToolSpec::setSpec(std::string key, std::string val) -> void
{
	if (specs.find(key) != specs.end())
		specs[key] = val;
	else
		specs.insert({ key, val });
}

auto ToolSpec::operator==(const ToolSpec& t) const-> bool
{
	if (specs == t.getAllSpecs())
		return true;
	return false;
}

