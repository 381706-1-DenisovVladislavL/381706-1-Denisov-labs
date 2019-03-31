#include "../TextLib/NodeIter.h"

TNodeIter::TNodeIter(TNode *r)
{
	root = cur = r;
	st.Put(root);
}

TNodeIter& TNodeIter::GoNext()
{
	cur = st.Get();
	if (cur->GetSosed() != 0)
	{
		st.Put(cur->GetSosed());
	}
	if (cur->GetNextLevel() != 0)
		st.Put(cur->GetNextLevel());
	return *this;
}

void TNodeIter::Reset()
{
	cur = root;
	while (!(st.IsEmpty()))
		st.Get();
	st.Put(cur);
}

bool TNodeIter::IsEnd()
{
	return st.IsEmpty();
}

TNode* TNodeIter::operator()()
{
	return cur;
}

TNodeIter& TNodeIter::operator++()
{
	return TNodeIter::GoNext();
}
