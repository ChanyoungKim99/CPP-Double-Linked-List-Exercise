#pragma once
#include "Monster.h"

struct MonsterList
{
	Monster* pHead;
	Monster* pTail;
};

Monster* CreateMonster(MonsterList&, const char*, const int);
int CountMonster(MonsterList&);
void PrintList(MonsterList&);
void PrintListRecursive(Monster*);
Monster* FindMonster(MonsterList&, const char*);
void DeleteList(MonsterList&);
bool DeleteMonster(MonsterList&, const char*);


