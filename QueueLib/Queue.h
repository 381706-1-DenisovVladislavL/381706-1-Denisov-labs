#pragma once

#include "Stack.h"

template <class T>
class TQueue : public TStack <T> {
protected:
  int start;
  int count;
public:
  TQueue(int n = 0);
  TQueue(TQueue <T> &q);
  virtual ~TQueue();

  void Put(T a);
  T Get();
  T TopView();

  bool IsFull();
  bool IsEmpty();

  void Print();
};

template <class T>
TQueue<T>::TQueue(int n) : TStack<T>(n) 
{ 
  start = 0; 
  count = 0; 
}

template <class T>
TQueue<T>::TQueue(TQueue<T> &q) : TStack<T>(q) 
{ 
  start = q.start; 
  count = q.count; 
}

template <class T>
TQueue<T>::~TQueue() {}

template <class T>
void TQueue<T>::Put(T a) 
{
  if (IsFull()) 
    throw TException("Queue is full.");
  else 
  {
    TStack<T>::Put(a);
    TStack<T>::top = TStack<T>::top % TStack<T>::size;
    count++;
  }  
}

template <class T>
T TQueue<T>::Get() 
{
  if (IsEmpty()) 
    throw TException("Queue is empty.");
  else 
  {
    T temp = TStack<T>::mas[start];
    start = (start + 1) % TStack<T>::size;
    count--;
    return temp;
  }
}

template<class T>
inline T TQueue<T>::TopView()
{
  return TStack<T>::mas[start];
}

template <class T>
bool TQueue<T>::IsFull() 
{
  if (count == TStack<T>::size)
    return true;
  else
    return false;
}

template <class T>
bool TQueue<T>::IsEmpty() 
{
  if (count == 0)
    return true;
  else 
    return false;
}

//template <class T>
//void TQueue<T>::Print()
//{
//  if (TQueue<T>::IsEmpty())
//    throw TException("Queue is empty.");
//  std::cout << "\nExit <-";
//  for (int i = TStack<T>::top, j = 1; j <= count; i = (i + 1) % TStack<T>::size, j++)
//    std::cout << "\t|" << TStack<T>::mas[i] << "| <-";
//  std::cout << " Enter"<< std::endl;
//}

template<class T>
void TQueue<T>::Print()
{
  if (TQueue<T>::IsEmpty())
    throw TException("Queue is empty.");
  for (int i = start; i < TStack<T>::top; i = (i + 1) % TStack<T>::size)
    std::cout << TStack<T>::mas[i];
  std::cout << std::endl;
}