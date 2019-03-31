#pragma once
#include "../TextLib/Node.h"

class TText
{
protected:
	TNode *root;
public:
	TText();
	char* Copy(int start, int n);
	char* Del(int start, int n);
	void Ins(TNode* start, TNode* d); //вставка
	TNode* Find(char* a); //поиск с возратом узла
	int FindIndex(char* a); //поиск с возвратом номера буквы

};