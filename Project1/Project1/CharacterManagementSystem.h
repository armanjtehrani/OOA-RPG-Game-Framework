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
	std::vector<std::shared_ptr<ToolSpec>> myToolSpecs;


	//
protected:
	virtual auto setMyName()->void = 0;

public:
	CharacterManagementSystem();

	auto getMyName()->CharacterManagerName;
	
public:
	auto useTool(std::shared_ptr<ToolSpec>)->void;
	auto unuseTool(std::shared_ptr<ToolSpec>)->Success;

protected:
	auto addToolSpecToMyToolSpecs(std::shared_ptr<ToolSpec>) -> void;
	auto removeToolSpecFromMyToolSpecs(std::shared_ptr<ToolSpec>) -> Success;
	
	virtual auto addSpecToMe(std::shared_ptr<ToolSpec>) -> void = 0;
	virtual auto removeSpecFromMe(std::shared_ptr<ToolSpec>) -> void = 0;

};


#endif // !RPG_CHARACTER_MANAGEMENT_SYSTEM_H_