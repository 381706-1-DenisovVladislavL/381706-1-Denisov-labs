#pragma once

#include "Elem.h"

template <class T>
class TList {
protected:
	TElem <T>* begin;
public:
	TList(); //конструктор по умолчанию
	TList(TList<T> &L); //конструктор копирования
	void PutBegin(T A); //положить элемнт в начало списка
	void PutEnd(T A); //положить элемент в конец списка
	//T GetBegin(); //взять с удалением из начала
	//T GetEnd(); //взять с удалением из конца
	//T GetElem(T* A); 
	//T* GetInd(T A);
	bool IsFull();
	bool IsEmpty();
};

//конструктор по умолчанию
template <class T>
TList<T>::TList()
{
	begin = 0;
}

//констуктор копирования
template <class T>
TList<T>::TList(TList<T> &L)
{
	TElem<T>* a = L.Begin, b;
	if (L.begin == 0)
		begin = 0;
	else {
		begin = new TElem<T>(*L.begin); //отрабатывает конструктор копирования для Telem; обращение по & к тому элементу, что пришел в constr copy для List
		b = begin;
		while (a->GetNext() != 0) {
			b->SetNext(new TElem<T>(*(a->GetNext()))); //new return *, Telem - constr copy, *(a->Get) --> &
			a = a->GetNext(); 
			b = b->GetNext();
		}
	}
}

//добавление в начало
template <class T>
void TList<T>::PutBegin(T A)
{
	if (begin == 0) {
		TElem<T>* tmp = new TElem <T>(A, 0);
		begin = tmp;
	}
	else {
		TElem<T>* tmp = new TElem <T>(A, begin);
		begin = tmp;
	}
}

//добавление в конец
template <class T>
void TList<T>::PutEnd(T A)
{

}

//template <class T>
//T TList<T>::GetBegin()
//{
//
//}
//
//template <class T>
//T TList<T>::GetEnd()
//{
//
//}
//
//template <class T>
//T TList<T>::GetElem(T* A)
//{
//
//}
//
//template <class T>
//T* TList<T>::GetInd(T A)
//{
//
//}

template <class T>
bool TList<T>::IsFull()
{
	try
	{
		TElem<T>* A = new TElem<T>();
		if (A == 0)
			return false;
		else {
			delete A;
			return true;
		}
	}
	catch (...)
		return false;
	//return true; Is this line useless? It's never going to be done.
}

template <class T>
bool TList<T>::IsEmpty()
{
	if (begin == 0)
		return true;
	else
		return false;
}