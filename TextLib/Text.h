#pragma once
#include "../TextLib/NodeIter.h"

class TText : public TNode
{
protected:
	TNode* root; //корень дерева
public:
	TText(const char* string); //конструктор преобразования строки в текст
	TText(TText& text); //конструктор копирования
	TText(TNode& node); //конструктор преобразования типа

	TNode* GetRoot(); //получение указателя на корень дерева

	void Insert(const int pos, const char* string); //вставка строки в указанную позицию
	void Insert(TNode* start, TNode* string); //вставка строки по указанному элементу в тексте

	int Find(const char* string); //поиск позиции строки в тексте
	TNode* FindNode(const char* string); //поиск элемента в тексте по указанной строке

	char* Copy(const int start, const int len); //копирования после указанной позиции start символов в кол-ве len
	TNode* Copy(TNode* start, const int len); //копирование после указанного элемента текста -//-

	void Delete(const int start_del, const int lenght); //удаление с указанной позиции -//-
	void Delete(TNode* start_del, const int lenght); //удаление с указанного элемента текста -//-
};