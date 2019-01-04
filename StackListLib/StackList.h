#pragma once

#include "../ExceptionLib/Exception.h"
#include "../ListLib/List.h"

template <class T>
class TStackList: protected TList <T> {
protected:
  int count;
public:
  TStackList();
  TStackList(TStackList<T> &s);
  virtual ~TStackList();

  void Put(T a);
  T Get();

  void Print();
};

template<class T>
TStackList<T>::TStackList() : TList<T>()
{
  count = 0;
}

template<class T>
TStackList<T>::TStackList(TStackList<T> &s) : TList<T>(s)
{
  count = s.count;
}

template<class T>
TStackList<T>::~TStackList()
{
  count = 0;
}

template<class T>
void TStackList<T>::Put(T a) 
{
  if (TList<T>::IsFull())
    throw TException("Stack is full.");
  TList<T>::PutBegin(a);
  count++;
}

template<class T>
T TStackList<T>::Get() 
{
  if (TList<T>::IsEmpty())
    throw TException("Stack is empty.");
  count--;
  return TList<T>::GetBegin();
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