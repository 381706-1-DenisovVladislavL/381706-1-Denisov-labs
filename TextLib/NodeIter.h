#pragma once
#include "../StackListLib/StackList.h"
#include "../TextLib/Node.h"

using namespace std;

class TNodeIter
{
protected:
	TNode* root;
	TNode* current;
	TStackList<TNode*> stack;
public:
	TNodeIter(TNode* _root);
	TNode* GoNext(); //перейти к следующему
	void Reset(); //вернуться к корню
	void PutInStack(TNode* node);
	bool IsEnd();
	TNode* operator()();
	TNodeIter& operator++();
};