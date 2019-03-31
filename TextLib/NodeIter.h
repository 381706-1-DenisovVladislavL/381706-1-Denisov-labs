#pragma once
#include "../StackListLib/StackList.h"
#include "../TextLib/Node.h"

using namespace std;

class TNodeIter
{
protected:
	TNode* root;
	TNode* cur;
	TStackList<TNode*> st;
public:
	TNodeIter(TNode*r); //конструктор по умолчанию
	TNodeIter& GoNext(); //перейти на следующий элемент
	void Reset(); //сбросить текущую позицию и установить указатель на начало
	bool IsEnd(); //если просмотр завершен, то вернет истину
	TNode* operator()();
	TNodeIter& operator++();
};