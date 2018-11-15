#pragma once

#include "Elem.h"

template <class T>
class TList {
protected:
	TElem <T>* begin;
public:
	TList();
	TList(TList<T> &L);
	void PutBegin();
	void PutEnd();
	//T GetBegin();
	//T GetEnd();
	//T GetElem(T* A);
	//T* GetInd(T A);
	//bool IsFull();
	//bool IsEmpty();
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

}

template <class T>
void TList<T>::PutBegin()
{

}

template <class T>
void TList<T>::PutEnd()
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
//
//template <class T>
//bool TList<T>::IsFull()
//{
//
//}
//
//template <class T>
//bool TList<T>::IsEmpty()
//{
//	if (begin == 0)
//		return true;
//	else
//		return false;
//}
//
