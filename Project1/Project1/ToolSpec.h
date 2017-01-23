#ifndef RPG_TOOL_SPEC_H_
#define RPG_TOOL_SPEC_H_


#include <unordered_map>
#include <string>


#include "CharacterManagerName.h"


class ToolSpec
{
	//
protected:
	CharacterManagerName partIAffect;
	std::unordered_map<std::string, std::string> specs;

	//
public:
	ToolSpec();

	auto getCharacterManagerIAffect() const->CharacterManagerName;
	auto setCharacterManagerIAffect(CharacterManagerName)->void;
	auto getAllSpecs() const->const std::unordered_map<std::string, std::string>&;
	auto setAllSpecs(std::unordered_map<std::string, std::string>)->void;
	auto getSpec(std::string) const->std::string;
	auto setSpec(std::string, std::string)->void;

	auto operator==(const ToolSpec& t) const->bool;
};

#endif // !RPG_TOOL_SPEC_H_