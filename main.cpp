#include "MonsterList.h"
#include <iostream>

int main()
{
	MonsterList myList{};

	CreateMonster(myList, "DEMON", 1000);
	CreateMonster(myList, "ORC", 200);
	CreateMonster(myList, "WOLF", 50);
	
	std::cout << CountMonster(myList) << std::endl;
	PrintList(myList);
	PrintListRecursive(myList.pHead);

	Monster* pFind = FindMonster(myList, "ORC");
	if (pFind == nullptr)
	{
		std::cout << "NOT FOUND!!" << std::endl;
	}
	else
	{
		std::cout << pFind->name << " : " << pFind->hp << " FOUND!!" << std::endl;
	}

	/*DeleteList(myList);
	std::cout << CountMonster(myList) << std::endl;*/

	DeleteMonster(myList, "WOLF");
	PrintList(myList);
}

