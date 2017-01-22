#ifndef RPG_TOOL_SPEC_H_
#define RPG_TOOL_SPEC_H_


#include <unordered_map>
#include <string>


#include "CharacterManagerName.h"


class ToolSpec
{
	//
private:
	CharacterManagerName partIAffect;
	std::unordered_map<std::string, std::string> specs;

	//
public:
	ToolSpec();

	auto getCharacterManagerIAffect()->CharacterManagerName;
	auto setCharacterManagerIAffect(CharacterManagerName)->void;
	auto getAllSpecs()->std::unordered_map<std::string, std::string>;
	auto setAllSpecs(std::unordered_map<std::string, std::string>)->void;
	auto getSpec(std::string)->std::string;
	auto setSpec(std::string, std::string)->void;

};

#endif // !RPG_TOOL_SPEC_H_