#pragma once
#include "../TextLib/MyString.h"

class TNode {

protected:
	TNode* nextLevel; // указатель на следующий уровень
	TNode* sosed; //указатель на соседа
	int level; //уровень листочка 0 - текст, 1 - строка, 2 - слово, 3 - символ.
	char data; // данное листочка
	
	static TNode* start; // начало
	static TNode* end; // конец
	static TNode* _free; // пустое место
	static char* mas; // память под текст
	static int sizeMas; // размер массива, где будет вся наша память

public:
	TNode(char c);
	TNode(TString s);
	TNode(int _level);
	TNode(TNode& other);

	TNode& operator=(const TNode& a);
	TNode& operator+=(TNode& a);
	TNode& operator+=(char c);
	TNode& operator+=(char* c);

	char* ToStr();
	TNode* Clone();

	int GetLevel();
	void SetLevel(int lev);

	TNode* GetNextLevel();
	void SetNextLevel(TNode* _nextLevel);

	TNode* GetSosed();
	void SetSosed(TNode* _sosed);

	char GetData();
	void SetData(char c);

	void Init(int size); // инициализация статических полей

	void* operator new (size_t n);
	void operator delete (void* a);
	static void Gc(); //сборщик мусора
};

