#include "Character.h"
#include "GameManager.h"

int main()
{
	auto t = std::make_shared<GameManager>();
	Character a(t);
	return 0;
}