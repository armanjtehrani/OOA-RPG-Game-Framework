#include "Character.h"
#include "GameManager.h"
#include <iostream>
using namespace std;
int main()
{
	auto t = std::make_shared<GameManager>();
	std::shared_ptr<Character> a = std::make_shared<Character>();
	t->addCharacter(a);
	if (t == a->getMainGameManager().lock())
		cout << "yess" << endl;

	system("pause");
	return 0;
}