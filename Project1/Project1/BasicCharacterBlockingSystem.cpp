#include "BasicCharacterBlockingSystem.h"



BasicCharacterBlockingSystem::BasicCharacterBlockingSystem()
{
	blocked = false;
	whoBlocked = HandlerName::NONE;
}


BasicCharacterBlockingSystem::~BasicCharacterBlockingSystem()
{
}

auto BasicCharacterBlockingSystem::isBlocked()->bool
{
	return blocked;
}

auto BasicCharacterBlockingSystem::whoBlockedMe()->HandlerName
{
	return this->whoBlocked;
}

auto BasicCharacterBlockingSystem::blockAs(HandlerName blocker)->bool
{
	if (this->isBlocked())
		return false;

	this->blocked = true;
	this->whoBlocked = blocker;
	return true;
}

auto BasicCharacterBlockingSystem::unblock()->void
{
	this->blocked = false;
	this->whoBlocked = HandlerName::NONE;
}
