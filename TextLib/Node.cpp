
#include "../TextLib/Node.h"

using namespace std;

int TNode::node_size = 100;
int TNode::busy_node_size = 0;
char* TNode::memory = 0;
TNode* TNode::start = NULL;
TNode* TNode::end = NULL;
TNode* TNode::cur_free = NULL;

//конструктор с параметром-уровнем (уровень 0-3)
TNode::TNode(const int _level)
{
	if (_level < 0 || _level > 3)
		throw TException("Error.");
	Initialization(node_size);
	level = _level;
	letter = 0;
	same_level = NULL;
	next_level = NULL;
}

//конструктор, формирующий слово (уровень 2)
TNode::TNode(const char* word)
{
	Initialization(node_size);
	int len = strlen(word);
	level = 2;
	same_level = NULL;
	next_level = new TNode(word[0]);
	TNode* tmp = next_level;
	for (int i = 1; i < len; i++)
	{
		tmp->same_level = new TNode(word[i]);
		tmp = tmp->same_level;
	}
	letter = 0;
}

//конструктор от буквы
TNode::TNode(const char _letter)
{
	Initialization(node_size);
	level = 3;
	letter = _letter;
	same_level = NULL;
	next_level = NULL;
}

//конструктор копирования звена
TNode::TNode(const TNode& node)
{
	Initialization(node_size);
	level = node.level;
	letter = node.letter;
	same_level = node.same_level;
	next_level = node.next_level;
}

//деструктор
TNode::~TNode()
{
	TNode* tmp;
	TStackList<TNode*> stack;
	stack.Put(this);
	if (stack.IsEmpty() == false)
		tmp = stack.Get();
	if (tmp->GetSameLevel() != NULL)
		stack.Put(tmp->GetSameLevel());
	if (tmp->GetNextLevel() != NULL)
		stack.Put(tmp->GetNextLevel());
	tmp->letter = -1;
}

TNode& TNode::operator=(const TNode& node)
{
	if (level != node.level)
		throw TException("Error.");
	if (this != &node)
	{
		same_level = node.same_level;
		next_level = node.next_level;
		letter = node.letter;
	}
	return *this;
}

TNode& TNode::operator+=(const TNode& node)
{
	TNode* tmp = this;
	if (level != node.level)
		while (tmp->level != node.level) //спускаемся в глубь, пока уровни не совпадут
			tmp = tmp->next_level;
	while (tmp->same_level != NULL) //сдвигаемся вправо до конца
		tmp = tmp->same_level;
	tmp->same_level = new TNode(node);  //добавляем то, что хотели
	return *this;
}

TNode& TNode::operator+=(const char _letter)
{
	TNode* tmp = new TNode(_letter);
	*this += *tmp; //этот оператор перегружен выше для аргумента TNode&
	return *this;
}

TNode& TNode::operator+=(const char* word)
{
	TNode* tmp = new TNode(word);
	*this += *tmp; //этот оператор перегружен выше для аргумента TNode&
	return *this;
}

void* TNode::operator new (const size_t size)
{
	if (cur_free != 0)
	{
		TNode* tmp = cur_free;
		if (busy_node_size == node_size)
			throw TException("No free memory.");
		cur_free = cur_free->next_level; //берем первую свободную ячейку и возвращаем ее пользователю
		busy_node_size++;
		return tmp;
	}
	return NULL;
}

void TNode::operator delete(void* node)
{
	TNode* tmp = (TNode*)node;
	tmp->next_level = cur_free; //в начало списка свободных вводим новый элемент
	cur_free = tmp; //началом списка свободных становится удаляемый элемент
	tmp->letter = -1; //маркер
	tmp->level = 0;
	tmp->same_level = NULL;
}

void TNode::SetSameLevel(TNode* _same_level)
{
	same_level = _same_level;
}

void TNode::SetNextLevel(TNode* _next_level)
{
	next_level = _next_level;
}

void TNode::SetLetter(const char _letter)
{
	if (level == 3)
		letter = _letter;
	else
		throw TException("Error.");
}

void TNode::SetLevel(const int _level)
{
	if ((_level < 0) || (_level > 3))
		throw TException("Error.");
	level = _level;
}

void TNode::SetNodeSize(const int size)
{
	node_size = size;
}

TNode* TNode::GetSameLevel()
{
	return same_level;
}

TNode* TNode::GetNextLevel()
{
	return next_level;
}

char TNode::GetLetter()
{
	if (level == 3)
		return letter;
	else
		throw TException("Error.");
}

int TNode::GetLevel()
{
	return level;
}

int TNode::GetNodeSize()
{
	return node_size;
}

int TNode::GetNodeBusySize()
{
	return busy_node_size;
}

//Приведение к красивому виду строки для дальнейшей печати на экран
char* TNode::ToString()
{
	TStackList<TNode*> stack;
	stack.Put(this);
	int len = 0;
	int space_array[100];
	int space_count = 0;
	bool trap = false;
	while (stack.IsEmpty() != true)
	{
		TNode* tmp = stack.Get();
		if (tmp->level == 3)
		{
			len++;
			if (trap == false && len > 1)
			{
				space_array[space_count] = len - 1;
				space_count++;
				len++;
			}
			trap = true;
		}
		if (tmp->same_level != NULL)
			stack.Put(tmp->same_level);
		if (tmp->next_level != NULL)
		{
			stack.Put(tmp->next_level);
			trap = false;
		}
	}
	char* res_string = new char[len + 1];
	int j = 0;
	stack.Put(this);
	space_count = 0;
	while (stack.IsEmpty() != true)
	{
		if (j == space_array[space_count])
		{
			res_string[j] = ' ';
			j++;
			space_count++;
		}
		TNode* tmp1 = stack.Get();
		if (tmp1->level == 3)
		{
			res_string[j] = tmp1->letter;
			j++;
		}
		if (tmp1->same_level != NULL)
			stack.Put(tmp1->same_level);
		if (tmp1->next_level != NULL)
			stack.Put(tmp1->next_level);
	}
	res_string[len] = 0;
	return res_string;
}

//копия
TNode* TNode::Clone()
{
	TNode* resNode = new TNode(*this);
	TStackList<TNode*> stack;
	TStackList<TNode*> copy;
	stack.Put(this);
	copy.Put(resNode);
	while (stack.IsEmpty() != true)
	{
		TNode* tmp1 = stack.Get();
		TNode* tmp2 = copy.Get();
		if (tmp1->next_level != NULL)
		{
			tmp2->next_level = new TNode(*(tmp1->next_level));
			stack.Put(tmp1->next_level);
			copy.Put(tmp2->next_level);
		}
		if (tmp1->same_level != NULL)
		{
			tmp2->same_level = new TNode(*(tmp1->same_level));
			stack.Put(tmp1->same_level);
			copy.Put(tmp2->same_level);
		}
	}
	return resNode;
}

void TNode::Initialization(const int size)
{
	if (size <= 0)
		throw TException("Error.");
	if (memory == 0)
	{
		node_size = size;
		memory = new char[sizeof(TNode) * size];
		start = (TNode*)(memory);
		cur_free = end = start;
		for (int i = 0; i < size - 1; i++)
		{
			end->next_level = (TNode*)(&memory[(i + 1) * sizeof(TNode)]);
			end = end->next_level;
		}
	}
}

//Сборка мусора
void TNode::GarbageCollector()
{
	cur_free = 0; // мы сбрасываем свободную пам¤ть
	for (int i = 0; i < node_size; i++)
	{
		int j = i * sizeof(TNode); //отсчет от начала массива свободных
		if (((TNode*)(&memory[j]))->letter == '-1') //очищаем, если стоит маркер
		{
			((TNode*)(&memory[j]))->next_level = cur_free; 
			cur_free = (TNode*)(&memory[j]); 
		}
	}
}

//Очистка памяти
void TNode::ClearMemory(void)
{
	delete[] memory;
	memory = NULL;
	busy_node_size = 0;
}

ostream& operator<<(ostream& os, TNode& node)
{
	char* str = node.ToString();
	os << str;
	return os;
}

//Технический вывод звеньев любого уровня
void TNode::Output()
{
	char* str = this->ToString();
	cout << str << endl;
}