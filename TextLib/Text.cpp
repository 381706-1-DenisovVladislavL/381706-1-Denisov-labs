#include "../TextLib/Text.h"
#include "../TextLib/NodeIter.h"

TText::TText()
{
	root = 0;
}

char * TText::Copy(int start, int n)
{

	return nullptr;
}

char * TText::Del(int start, int n)
{
	return nullptr;
}

void TText::Ins(TNode* start, TNode* d)
{
}

TNode* TText::Find(char* a)
{
	TNodeIter i(root);
	for (; i.IsEnd(); i.operator++())
	{
		if (i()->GetData() == a[0])
		{
			bool f = true;
			TNodeIter j = i;
			int t = 1;
			while ((!(j.IsEnd())) && (a[t]!='\0'))
			{
				if (j()->GetData() != a[t])
				{
					f = false;
					break;
				}
				t++;
			}
			if (f = true)
				return i();
		}
	}
	return nullptr;
}

int TText::FindIndex(char * a)
{
	return 0;
}

