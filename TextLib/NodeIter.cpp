#include "../TextLib/NodeIter.h"

TNodeIter::TNodeIter(TNode* _root)
{
	root = _root;
	current = root;
	stack.Put(root);
}

TNode* TNodeIter::GoNext()
{
	TNode* tmp;
	if (stack.IsEmpty() == false)
		tmp = stack.Get();
	if (tmp->GetSameLevel() != NULL)
		stack.Put(tmp->GetSameLevel());
	if (tmp->GetNextLevel() != NULL)
		stack.Put(tmp->GetNextLevel());
	current = tmp;
	return current;
}

void TNodeIter::Reset()
{
	stack.Clear();
	stack.Put(root);
	current = root;
}

bool TNodeIter::IsEnd()
{
	if (stack.IsEmpty() == true)
		return true;
	else
		return false;
}

void TNodeIter::PutInStack(TNode* node)
{
	stack.Put(node);
}

TNode* TNodeIter::operator()()
{
	return current;
}

TNodeIter& TNodeIter::operator++()
{
	TNodeIter tmp(root);
	return tmp;
}