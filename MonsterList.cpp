#include "MonsterList.h"
#include <cstring>
#include <iostream>

Monster* CreateMonster(MonsterList& list, const char* name, const int hp)
{
    Monster* pNew = new Monster{};
    strcpy_s(pNew->name, NAME_LENGTH, name);
    pNew->hp = hp;

    if (list.pTail == nullptr)
    {
        list.pHead = pNew;
        list.pTail = pNew;
    }
    else
    {
        list.pTail->pNext = pNew;
        pNew->pPrev = list.pTail;
        list.pTail = pNew;
    }
    return pNew;
}

int CountMonster(MonsterList& list)
{
    int count{};
    Monster* pElement = list.pHead;
    while (pElement != nullptr)
    {
        count++;
        pElement = pElement->pNext;
    }
    return count;
}

void PrintList(MonsterList& list)
{
    Monster* pElement = list.pHead;

    while (pElement != nullptr)
    {
        std::cout << pElement->name << " : " << pElement->hp << std::endl;
        pElement = pElement->pNext;
    }
}

void PrintListRecursive(Monster* head)
{
    Monster* pElement = head;

    if (pElement == nullptr)
    {
        return;
    }

    std::cout << pElement->name << " : " << pElement->hp << std::endl;
    PrintListRecursive(pElement->pNext);
}

Monster* FindMonster(MonsterList& list, const char* name)
{
    Monster* pElement = list.pHead;

    while (pElement != nullptr)
    {
        if (strcmp(pElement->name, name) == 0)
        {
            return pElement;
        }
        pElement = pElement->pNext;
    }
    return nullptr;
}

void DeleteList(MonsterList& list)
{
    Monster* pElement = list.pHead;
    Monster* pTemp{};                       // 주의! nullptr 참조하지 않도록...

    while (pElement != nullptr)
    {
        pTemp = pElement->pNext;
        delete pElement;
        pElement = pTemp;
    }
    list.pHead = list.pTail = nullptr;
}

bool DeleteMonster(MonsterList& list, const char* name)
{
    Monster* pElement = FindMonster(list, name);
    
    if (pElement == nullptr)
    {
        return false;
    }
    else if (list.pHead == list.pTail)
    {
        list.pHead = list.pTail = nullptr;
    }
    else if (pElement == list.pHead)
    {
        list.pHead = pElement->pNext;
        list.pHead->pPrev = nullptr;        // 주의!!!  dangling pointer
    }
    else if (pElement == list.pTail)
    {
        list.pTail = pElement->pPrev;
        list.pTail->pNext = nullptr;        // 주의!!!  dangling pointer
    }
    else
    {
        pElement->pPrev->pNext = pElement->pNext;
        pElement->pNext->pPrev = pElement->pPrev;
    }
    delete pElement;
    return true;
}
