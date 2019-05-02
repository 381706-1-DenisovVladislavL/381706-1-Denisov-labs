#pragma once
#include "../StackListLib/StackList.h"
#include <cstring>
#include <iostream>

using namespace std;

class TNode
{
protected:
	TNode* same_level; //��������� �� ��������� ������� ������
	TNode* next_level; //��������� �� ���������� ������� � ������� �������� ������
	char letter; //�����
	int level; //������� �������

	static char* memory;
	static TNode* start;
	static TNode* end;
	static TNode* cur_free; //��������� �� ������� ������� � ����� ������
	static int node_size; //����������� ��������� ����� ���������
	static int busy_node_size; //����� ������� ���������
public:
	TNode(const int _level);
	TNode(const char* word);
	TNode(const char _letter = 0);
	TNode(const TNode& node);
	~TNode();

	TNode& operator=(const TNode& node);
	TNode& operator+=(const TNode& node);
	TNode& operator+=(const char _letter);
	TNode& operator+=(const char* word);

	void* operator new (const size_t size);
	void operator delete (void* node);

	void SetSameLevel(TNode* _same_level);
	void SetNextLevel(TNode* _next_level);
	void SetLetter(const char _letter);
	void SetLevel(const int _level);
	static void SetNodeSize(const int size);

	TNode* GetSameLevel();
	TNode* GetNextLevel();
	char GetLetter();
	int GetLevel();
	static int GetNodeSize();
	static int GetNodeBusySize();

	void Initialization(const int size = 100);
	void GarbageCollector();
	static void ClearMemory(void);

	TNode* Clone();
	char* ToString();
	void Output();
	friend ostream& operator<<(ostream& os, TNode& text);
};

