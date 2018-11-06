#pragma once

#include "Stack.h"

template <class T>
class TQueue : public TStack <T> {
protected:
	int Start;
	int Count;
public:
	TQueue(int n = 0);
	TQueue(TQueue <T> &Q);
	void Put(T A);
	T Get();
	bool IsFull();
	bool IsEmpty();
};

template <class T>
TQueue<T>::TQueue(int n) : TStack<T>(n) { Start = 0; Count = 0; }

template <class T>
TQueue<T>::TQueue(TQueue <T> &Q) : TStack(TStack<T> Q) { Start = Q.Start; Count = Q.Count; }

template <class T>
void TQueue<T>::Put(T A) {
	if (IsFull()) 
		throw 1;
	else {
		TStack<T>::Mas[Start] = A;
		Start = (Start + 1) % TStack<T>::Size;
		Count++;
	}	
}

template <class T>
T TQueue<T>::Get() {
	if (IsEmpty()) 
		throw 1;
	else {
		T temp = Mas[Top];
		TStack<T>::Top = (TStack<T>::Top + 1) % TStack<T>::Size;
		Count--;
		return temp;
	}
}

template <class T>
bool TQueue<T>::IsFull() {
	if (Count == TStack<T>::Size)
		return true;
	else
		return false;
}

template <class T>
bool TQueue<T>::IsEmpty() {
	if (Count == 0)
		return true;
	else 
		return false;
}