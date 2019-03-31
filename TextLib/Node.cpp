#include "../StackListLib/StackList.h"
#include "../TextLib/Node.h"

using namespace std;

TNode* TNode::start = 0;
TNode* TNode::end = 0;
TNode* TNode::_free = 0;
char* TNode::mas = 0;
int TNode::sizeMas = 0;

TNode::TNode(char c)
{
	Init(10);
	nextLevel = NULL;
	sosed = NULL;
	level = 3; 
	data = c;
}

TNode::TNode(TString s)
{
	if (s.GetLength() == 0)
		throw TException("Inccorrect string");
	Init(10);
	data = 0;
	nextLevel = new TNode(s[0]);
	level = 2;
	sosed = 0;
	TNode *a = nextLevel;
	for (int i = 1; i < s.GetLength(); i++)
	{
		a->SetSosed(new TNode(s[i]));
		a = a->GetSosed();
	}
}

TNode::TNode(int _level)
{
	if ((_level < 0) || (_level > 3))
		throw TException("Incorrect level");
	Init(10);
	nextLevel = 0;
	sosed = 0;
	level = _level;
	data = -1;
}

TNode::TNode(TNode& other) 
{
	Init(10);
	data = other.data;
	nextLevel = other.nextLevel;
	sosed = other.sosed;
	level = other.level;
}

TNode& TNode::operator=(const TNode& a)
{
	data = a.data;
	level = a.level;
	sosed = a.sosed;
	nextLevel = a.nextLevel;
	return *this;
}


TNode& TNode::operator+=(TNode& a)
{
	if (level < a.level)
		throw TException("Incorrect level");
	TStackList<TNode*> st;
	st.Put(this);		//����� � ���� ��������� �� ��������
	bool flag = true;
	TNode* t;
	while (flag || st.IsEmpty()) //������� �� ���� �����, ���� ����� ���������, ���������, ����� ���������� ���� � ������� �� �����
	{
		t = st.Get();
		if (t->nextLevel != 0)
			st.Put(t->nextLevel);
		if (t->sosed != 0)
			st.Put(t->sosed);
		if ((t->level = a.level) && (t->sosed == 0))
		{
			flag = false;
			t->sosed = a.Clone();
		}
	}
	return *this;
}

TNode& TNode::operator+=(char c)
{
	TNode simbol(c);
	return (*this += simbol);
}

TNode& TNode::operator+=(char* c)
{
	TNode slovo(c);
	return (*this += slovo);
}

char* TNode::ToStr()
{
	int l = 0;
	int j = 0;
	TStackList<TNode*> st;
	TNode* t;
	st.Put(this);
	while (!st.IsEmpty()) //����� � ����� �������� ������
	{
		t = st.Get();
		if (t->nextLevel != 0)
			st.Put(t->nextLevel);
		if (t->sosed != 0)
			st.Put(t->sosed);
		if (t->level == 3)
			l++;
	}
	char* res = new char[l + 1];
	st.Put(this);
	while (!st.IsEmpty()) //����� � ����� ������ ��������� � ������
	{
		t = st.Get();
		if (t->level == 3)
		{
			res[j] = t->data;
			j++;
		}
		if (t->sosed != 0)
			st.Put(t->sosed);
		if (t->nextLevel != 0)
			st.Put(t->nextLevel);
	}
	res[l] = 0;
	return res;
}

TNode* TNode::Clone()
{
	TNode* res = new TNode(*this);
	TStackList<TNode*> st;
	TStackList<TNode*> copy;
	st.Put(this);
	copy.Put(res);
	while (!st.IsEmpty())
	{
		TNode* t = st.Get();
		TNode* c = copy.Get();
		if (t->sosed != 0)
		{
			c->sosed = new TNode(*(t->sosed));
			st.Put(t->sosed);
			copy.Put(c->sosed);
		}
		if (t->nextLevel != 0)
		{
			c->nextLevel = new TNode(*(t->nextLevel));
			st.Put(t->nextLevel);
			copy.Put(c->nextLevel);
		}
	}
	return res;
}

int TNode::GetLevel()
{
	return level;
}

void TNode::SetLevel(int lev)
{
	if ((lev < 0) || (lev > 3))
		throw TException("Incorrect level");
}

TNode* TNode::GetNextLevel()
{
	return nextLevel;
}

void TNode::SetNextLevel(TNode* _nextLevel)
{
	nextLevel = _nextLevel;
}

TNode* TNode::GetSosed()
{
	return sosed;
}

void TNode::SetSosed(TNode* _sosed)
{
	sosed = _sosed;
}

char TNode::GetData()
{
	return data;
}

void TNode::SetData(char c)
{
	data = c;
}

void TNode::Init(int size)
{
	if (mas == 0) // ���� ��� ��� ���� ���������������� �� ���, �� ������ �� ������!
	{
		sizeMas = size;
		int l = size * sizeof(TNode);
		mas = new char[l];
		start = (TNode*)(mas); //��������������� ������ ������� ������� � ��������� ���� ������ ������
		end = _free = start;
		for (int i = 1; i < size; i++)
		{
			int j = i * sizeof(TNode);
			end->sosed = (TNode*)(&mas[j]);
			end = end->sosed;
		}
		end->sosed = 0;
	}
}

void* TNode::operator new(size_t n)
{
	if (_free != 0)
	{
		TNode* a;
		a = _free; // ����� ������ ��������� ������ � ���������� �� ������������
		_free = _free->sosed; // � �� ��� ������ ��������� �� ���������
		return a;
	}
	return NULL;
}

void TNode::operator delete(void * a)
{
	TNode* t = (TNode*)(a);
	t->sosed = _free; // ����� � ������ ������ ������ ��� ���� �������
	_free = t;
	t->data = -1;
}

void TNode::GarbageCollector()
{
	_free = 0; // �� ���������� ��������� ������
	for (int i = 0; i < sizeMas; i++)
	{
		int j = i * sizeof(TNode);
		if (((TNode*)(&mas[j]))->data == '-1')
		{
			((TNode*)(&mas[j]))->sosed = _free;
			_free = (TNode*)(&mas[j]);
		}
	}
}


//// _______________________________________________________________________________________________________________________________
//// main.cpp
////
//#include <iostream>
//
//int main(int argc, char argv[])
//{
//	TNode tmp;
//
//	// ������ ������������� ���������
//	TNode S("stroka");
//	for (TNodeIter i(s); i.IsEnd; i++)
//	{
//		std::cout << i();
//	}
//
//	return 0;
//}
//
//// ���� ����� �������� ����� ��������, ������� �� ����� ������ �� ������� �������� �������