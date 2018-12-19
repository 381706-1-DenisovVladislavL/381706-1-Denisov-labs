#pragma once

#include "../ExceptionLib/Exception.h"
#include "../ListLib/List.h"

template <class T>
class TStackList: protected TList <T> {
protected:
  int size;
  int count;
public:
  TStackList(int _size = 5);
  TStackList(TStackList<T> &s);
  virtual ~TStackList();

  void Put(T a);
  T Get();

  bool IsFull();
  bool IsEmpty();

  void Print();
};

template<class T>
TStackList<T>::TStackList(int _size) : TList<T>()
{
  if (_size <= 0)
    throw TException("Negative Stack size.");
  size = _size;
  count = 0;
}

template<class T>
TStackList<T>::TStackList(TStackList<T> &s) : TList<T>(s)
{
  size = s.size;
  count = s.count;
}

template<class T>
TStackList<T>::~TStackList()
{
  size = 0;
  count = 0;
}

template<class T>
void TStackList<T>::Put(T a) 
{
  if (TStackList<T>::IsFull())
    throw TException("Stack is full.");
  TList<T>::PutBegin(a);
  count++;
}

template<class T>
T TStackList<T>::Get() 
{
  if (TStackList<T>::IsEmpty())
    throw TException("Stack is empty.");
  count--;
  return TList<T>::GetBegin();
}

template <class T>
bool TStackList<T>::IsFull() 
{
  if (size == count)
    return true;
  else
    return false;
}

template <class T>
bool TStackList<T>::IsEmpty()
{
  return TList<T>::IsEmpty();
}

template <class T>
void TStackList<T>::Print() 
{
  if (TStackList<T>::IsEmpty())
    throw TException("Stack is empty.");
  TElem<T> *temp = TList<T>::begin;
  do
  {
    std::cout << "\t|" << temp->TElem<T>::GetData() << "| " << std::endl;
    temp = temp->GetNext();
  } while (temp != 0);
  std::cout << std::endl;
}