#pragma once

#include <iostream>

#include "../StackLib/Stack.h"
#include "../ExceptionLib/Exception.h"

template <class T>
class TNewStack :public TStack<T> {
public:
	TNewStack(int _Size = 0, T* _Mas = 0) {
		TStack<T>::Size = _Size;
		TStack<T>::Top = 0;
		if (_Mas == 0) TStack<T>::Mas = 0; 
		else {
			TStack<T>::Mas = _Mas;
		}
	}
	TNewStack(TNewStack <T> &NS) {
		TStack<T>::Size = NS.TStack<T>::Size;
		TStack<T>::Top = NS.TStack<T>::Top;
		if (NS.TStack<T>::Mas == 0) TStack<T>::Mas = 0;
		else {
			TStack<T>::Mas = NS.TStack<T>::Mas;
		}
	}
	int CountFree() {
		return (TStack<T>::Size - TStack<T>::Top);
	}
	int GetSize() {
		return TStack<T>::Size;
	}
	void SetMas(int _Size, T* _Mas) {
		TStack<T>::Size = _Size;
		TStack<T>::Mas = _Mas;
	}
};

template <class T>
class TMStack {
protected:
	int Size;
	T* Mas;
	int N;
	TNewStack<T>** NS;
	int GetFreeMem();
//	void Repack();
public:
	TMStack(int _Size, int _N);
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
		for (int i = 0; i < Size; i++)
			cout << i << " " << TMStack<T>::Mas[i] << endl;
		cout << endl;
	}
};

template <class T>
TMStack<T>::TMStack(int _Size, int _N) {
	if ((_N <= 0) || (_Size <= 0))
		throw "Not positive dimension or number of stacks.";
	N = _N;
	Size = _Size;
	Mas = new T[Size];
	NS = new TNewStack<T>*[N];
	for (int i = 0; i < Size; i++) 
		Mas[i] = 0;
	int* p = new int[N]; //массив размеров каждой части мультистека
	p[0] = (int(double(Size) / N) + (Size % N));
	for (int i = 1; i < N; i++)
		p[i] = int(double(Size) / N);
	NS[0] = new TNewStack<T>(p[0], &Mas[0]);
	for (int i = 1; i < N; i++)
		NS[i] = new TNewStack<T>(p[1], &Mas[p[0] + (i - 1) * int(double(Size) / N)]);
}


//Конструктор копирования пока не работает
template <class T>
TMStack<T>::TMStack(TMStack<T> &MS) {
	Size = MS.Size;
	N = MS.N;
	Mas = new T[Size];
	NS = new TNewStack<T>*[N];
	for (int i = 0; i < Size; i++) 
		Mas[i] = MS.Mas[i];
	int* p = new int[N];
	for (int i = 0; i < N; i++)
		p[i] = MS.NS[i]->TNewStack<T>::GetSize();
	int SizeCounter = 0;
	NS[0] = new TNewStack<T>(*(MS.NS[0]));
	for (int i = 1; i < N; i++)
	{
		NS[i] = new TNewStack<T>(*(MS.NS[i]));
		NS[i]->TNewStack<T>::SetMas(p[i], &Mas[p[0] + SizeCounter]);
		SizeCounter += p[i - 1];
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
	if (_N < 0 || _N >= Size)
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
	if (_N < 0 || _N >= Size)
		throw "Out-of-range.";
	NS[_N]->TStack<T>::IsFull();
}

template <class T>
bool TMStack<T>::ISEmpty(int _N) {
	if (_N < 0 || _N >= Size)
		throw "Out-of-range.";
	NS[_N]->TStack<T>::IsEmpty();
}
