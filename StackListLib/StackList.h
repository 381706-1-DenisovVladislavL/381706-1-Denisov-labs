#pragma once

#include "../ExceptionLib/Exception.h"
#include "../ListLib/List.h"

template <class T>
class TStackList: protected TList <T> {
public:
  TStackList();
  TStackList(TStackList<T> &s);
  virtual ~TStackList();

  void Put(T a);
  T Get();

  bool IsEmpty();

  void Print();
};

template<class T>
TStackList<T>::TStackList() : TList<T>() {}

template<class T>
TStackList<T>::TStackList(TStackList<T> &s) : TList<T>(s) {}

template<class T>
TStackList<T>::~TStackList() {}

template<class T>
void TStackList<T>::Put(T a) 
{
  if (TList<T>::IsFull())
    throw TException("Stack is full.");
  TList<T>::PutBegin(a);
}

template<class T>
T TStackList<T>::Get() 
{
  if (TList<T>::IsEmpty())
    throw TException("Stack is empty.");
  return TList<T>::GetBegin();
}

template<class T>
bool TStackList<T>::IsEmpty()
{
	return TList<T>::IsEmpty();
}

template <class T>
void TStackList<T>::Print() 
{
  if (TList<T>::IsEmpty())
    throw TException("Stack is empty.");
  TElem<T> *temp = TList<T>::begin;
  do
  {
    std::cout << "\t|" << temp->TElem<T>::GetData() << "| " << std::endl;
    temp = temp->GetNext();
  } while (temp != 0);
  std::cout << std::endl;
}