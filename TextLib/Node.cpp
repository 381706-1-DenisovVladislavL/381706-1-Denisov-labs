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
	nextLevel = NULL;
	sosed = NULL;
	level = 3; 
	data = c;
}

TNode::TNode(TString s)
{
	if (s.GetLength() == 0)
		throw TException("Inccorrect string");
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
	nextLevel = 0;
	sosed = 0;
	level = _level;
	data = -1;
}

TNode::TNode(TNode& other) 
{
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
	st.Put(this);		//кладём в стек указатель на исходный
	bool flag = true;
	TNode* t;
	while (flag || st.IsEmpty()) //доходим до того места, куда нужно вставлять, вставляем, потом опусташаем стек и выходим из цикла
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
	while (!st.IsEmpty()) //обход с целью подсчёта листов
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
	while (!st.IsEmpty()) //обход с целью записи элементов в строку
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
	if (mas == 0) // если это уже было инициализировано до нас, то ничего не делаем!
	{
		sizeMas = size;
		int l = size * sizeof(TNode);
		mas = new char[l];
		start = (TNode*)(mas); //преобразовываем первый элемент массива в указатель типа нашего класса
		end = _free = start;
		for (int i = 1; i < size; i++)
		{
			int j = i * sizeof(TNode);
			end->nextLevel = (TNode*)(&mas[j]);
		}
		end->nextLevel = 0;
	}
}

void * TNode::operator new(size_t n)
{
	if (_free != 0)
	{
		TNode* a = _free; // берем первую свободную ячейку и возвращаем ее пользователю
		_free = _free->nextLevel; // а во фри кладет указатель на следующий
		return a;
	}
	return NULL;
}

void TNode::operator delete(void * a)
{
	TNode* t = (TNode*)(a);
	t->nextLevel = _free; // слово в начало списка вводим еще один элемент
	_free = t;
	t->data = -1;
}

void TNode::Gc()
{
	_free = 0; // мы сбрасываем свободную память
	for (int i = 0; i < sizeMas; i++)
	{
		int j = i * sizeof(TNode);
		if (((TNode*)(&mas[j]))->data == '-1')
		{
			((TNode*)(&mas[j]))->nextLevel = _free;
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
//	// пример использования итератора
//	TNode S("stroka");
//	for (TNodeIter i(s); i.IsEnd; i++)
//	{
//		std::cout << i();
//	}
//
//	return 0;
//}
//
//// дома нужно написать умный итератор, который не будет дважды по первому элементу шастать
