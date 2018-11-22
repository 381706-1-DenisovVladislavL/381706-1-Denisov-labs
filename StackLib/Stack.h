#pragma once
#include <iostream>

template <class T>
class TStack {
protected:
	int Size;
	int Top;
	T* Mas;
public:
	TStack(int n = 0);
	TStack(TStack<T> &S);
	virtual ~TStack();

	void Put(T A);
	T Get();

	bool IsFull();
	bool IsEmpty();
};

//Конструктор по умолчанию
template <class T>
TStack <T> :: TStack(int n) {
	if (n < 0) throw 1;
	else 
		if (n == 0) {
			Size = Top = 0;
			Mas = NULL;
		}
		else {
			Size = n;
			Top = 0;
			Mas = new T[Size];
			for (int i = 0; i < Size; i++)
				Mas[i] = 0;
		}
}

//Конструктор копирования
template <class T>
TStack <T> :: TStack(TStack <T> &S) {
	Size = S.Size;
	Top = S.Top;
	if (Size == 0)
		Mas = NULL;
	else {
		Mas = new T[Size];
		for (int i = 0; i < Size; i++)
			Mas[i] = S.Mas[i];
	}
}

template<class T>
TStack <T> :: ~TStack() {
	delete[] Mas;
}

//Добавление элемента
template <class T>
void TStack<T> :: Put(T A) {
	if (IsFull())
		throw 1;
	else {
		Mas[Top] = A;
		Top++;
	}
}

//Удаление элемента
template <class T>
T TStack<T> :: Get() {
	if (IsEmpty()) 
		throw 1;
	else {
		Top--;
		return Mas[Top];
	}
}

//Проверка на полноту
template <class T>
bool TStack<T> :: IsFull() {
	if (Top >= Size)
		return true;
	else
		return false;
}

//Проверка на пустоту
template <class T>
bool TStack<T> :: IsEmpty() {
	if (Top == 0)
		return true;
	else
		return false;
}