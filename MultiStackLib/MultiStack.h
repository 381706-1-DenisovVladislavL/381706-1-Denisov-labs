#pragma once

#include <iostream>

#include "../StackLib/Stack.h"
#include "../ExceptionLib/Exception.h"

template <class T>
class TNewStack :public TStack<T> {
public:
	TNewStack(int _size = 0, T* _mas = 0) {
		TStack<T>::size = _Size;
		TStack<T>::top = 0;
		if (_mas == 0) TStack<T>::mas = 0; 
		else {
			TStack<T>::mas = _mas;
		}
	}
	TNewStack(TNewStack <T> &NS) {
		TStack<T>::size = NS.TStack<T>::size;
		TStack<T>::top = NS.TStack<T>::top;
		if (NS.TStack<T>::mas == 0) TStack<T>::mas = 0;
		else {
			TStack<T>::mas = NS.TStack<T>::mas;
		}
	}
	int CountFree() {
		return (TStack<T>::size - TStack<T>::top);
	}
	int GetSize() {
		return TStack<T>::size;
	}
	void SetMas(int _size, T* _mas) {
		TStack<T>::size = _size;
		TStack<T>::mas = _mas;
	}
};

template <class T>
class TMStack {
protected:
	int size;
	T* mas;
	int N;
	TNewStack<T>** NS;
	int GetFreeMem();
//	void Repack();
public:
	TMStack(int _size, int _N);
	TMStack(TMStack<T> &MS);
	void Put(int _N, T A);
	T Get(int _N);
	bool IsFull(int _N);
	bool ISEmpty(int _N);
	
	//Временный метод
	int Test() {
		return GetFreeMem();
	}

	void Print() {
		for (int i = 0; i < size; i++)
			std::cout << i << " " << TMStack<T>::mas[i] << std::endl;
		std::cout << std::endl;
	}
};

template <class T>
TMStack<T>::TMStack(int _size, int _N) {
	if ((_N <= 0) || (_size <= 0))
		throw "Not positive dimension or number of stacks.";
	N = _N;
	size = _size;
	mas = new T[size];
	NS = new TNewStack<T>*[N];
	for (int i = 0; i < size; i++) 
		mas[i] = 0;
	int* p = new int[N]; //массив размеров каждой части мультистека
	p[0] = (int(double(size) / N) + (size % N));
	for (int i = 1; i < N; i++)
		p[i] = int(double(size) / N);
	NS[0] = new TNewStack<T>(p[0], &mas[0]);
	for (int i = 1; i < N; i++)
		NS[i] = new TNewStack<T>(p[1], &mas[p[0] + (i - 1) * int(double(size) / N)]);
}


//Конструктор копирования пока не работает
template <class T>
TMStack<T>::TMStack(TMStack<T> &MS) {
	size = MS.size;
	N = MS.N;
	mas = new T[size];
	NS = new TNewStack<T>*[N];
	for (int i = 0; i < size; i++) 
		mas[i] = MS.mas[i];
	int* p = new int[N];
	for (int i = 0; i < N; i++)
		p[i] = MS.NS[i]->TNewStack<T>::GetSize();
	int sizeCounter = 0;
	NS[0] = new TNewStack<T>(*(MS.NS[0]));
	for (int i = 1; i < N; i++)
	{
		NS[i] = new TNewStack<T>(*(MS.NS[i]));
		NS[i]->TNewStack<T>::SetMas(p[i], &mas[p[0] + SizeCounter]);
		sizeCounter += p[i - 1];
	}
}

template <class T>
int TMStack<T>::GetFreeMem() {
	int count = 0;
	for (int i = 0; i < N; i++)
		count += NS[i]->CountFree();
	return count;
}

//template <class T>
//void TMStack<T>::Repack() {
//
//}

template <class T>
void TMStack<T>::Put(int _N, T A) {
	if (_N < 0 || _N >= size)
		throw "Out-of-range.";
	//if (IsFull(_N)) Repack();
	NS[_N]->TStack<T>::Put(A);
}

template <class T>
T TMStack<T>::Get(int _N) {
	if (_N >= 0 && _N < N)
		return (NS[_N]->TStack<T>::Get());
	else
		throw "Out-of-range.";
}
//
template <class T>
bool TMStack<T>::IsFull(int _N) {
	if (_N < 0 || _N >= size)
		throw "Out-of-range.";
	NS[_N]->TStack<T>::IsFull();
}

template <class T>
bool TMStack<T>::ISEmpty(int _N) {
	if (_N < 0 || _N >= size)
		throw "Out-of-range.";
	NS[_N]->TStack<T>::IsEmpty();
}
