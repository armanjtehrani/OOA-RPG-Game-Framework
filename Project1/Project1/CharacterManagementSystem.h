#ifndef RPG_CHARACTER_MANAGEMENT_SYSTEM_H_
#define RPG_CHARACTER_MANAGEMENT_SYSTEM_H_


#include <memory>
#include <vector>

#include "Success.h"

#include "CharacterManagerName.h"

#include "ToolSpec.h"

class CharacterManagementSystem
{
	//attributes
private:
	CharacterManagerName myName;
	std::vector<std::weak_ptr<ToolSpec>> myToolSpecs;


	//
private:
	virtual auto setMyName()->void;

public:
	auto getMyName()->CharacterManagerName;
	
public:
	virtual auto useTool(std::weak_ptr<ToolSpec>)->void;
	virtual auto unuseTool(std::weak_ptr<ToolSpec>)->Success;
};


#endif // !RPG_CHARACTER_MANAGEMENT_SYSTEM_H_