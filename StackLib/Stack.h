#pragma once
#include <iostream>
#include "../ExceptionLib/Exception.h"

template <class T>
class TStack {
protected:
  int size;
  int top;
  T* mas;
public:
  TStack(int n = 0);
  TStack(TStack<T> &s);
  virtual ~TStack();

  void Put(T a);
  T Get();

  void Print();

  bool IsFull();
  bool IsEmpty();
};

template <class T>
TStack <T> :: TStack(int n) 
{
  if (n < 0) 
    throw TException("Negative Stack size.");
  if (n == 0) 
  {
    size = top = 0;
    mas = NULL;
  }
  else 
  {
    size = n;
    top = 0;
    mas = new T[size];
    for (int i = 0; i < size; i++)
      mas[i] = 0;
  }
}

template <class T>
TStack <T> :: TStack(TStack <T> &s) 
{
  size = s.size;
  top = s.top;
  if (size == 0)
    mas = NULL;
  else 
  {
    mas = new T[size];
    for (int i = 0; i < size; i++)
      mas[i] = s.mas[i];
  }
}

template<class T>
TStack <T> :: ~TStack() 
{
  delete[] mas;
}

template <class T>
void TStack<T> :: Put(T a) 
{
  if (IsFull()) 
  {
    TException exp("Stack is full!");
    throw exp;
  }
  mas[top] = a;
  top++;
}

template <class T>
T TStack<T> :: Get()
{
  if (IsEmpty()) 
  {
    TException exp("Stack is empty!");
    throw exp;
  }
  top--;
  return mas[top];
}

template <class T>
void TStack<T>::Print()
{
  for (int i = top - 1; i >= 0; i--)
    std::cout << "\t|" << mas[i] << "|" << std::endl;
}

template <class T>
bool TStack<T> :: IsFull() 
{
  if (top >= size)
    return true;
  else
    return false;
}

template <class T>
bool TStack<T> :: IsEmpty() 
{
  if (top == 0)
    return true;
  else
    return false;
}