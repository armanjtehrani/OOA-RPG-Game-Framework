#ifndef RPG_TOOL_H_
#define RPG_TOOL_H_


#include <vector>

#include "Success.h"
#include "ToolSpec.h"
class Tool
{
	//
private:
	std::vector<ToolSpec> mySpecs;
	
	//
public:
	auto addSpec(ToolSpec)->Success;
	auto removeSpec(ToolSpec)->Success;
	auto getSpecs(CharacterManagerName)const->std::vector<ToolSpec>;
	auto getAllSpecs()const->const std::vector<ToolSpec>&;

};

#endif // !RPG_TOOL_H_