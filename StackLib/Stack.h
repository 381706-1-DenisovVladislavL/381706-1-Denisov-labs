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
  TStack(TStack<T> &stack);
  virtual ~TStack();

  void Put(T a);
  T Get();
  T TopView();

  int GetSize();

  void Print();

  bool IsFull();
  bool IsEmpty();

  TStack& operator=(const TStack<T> &stack);
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
TStack <T> :: TStack(TStack <T> &stack) 
{
  size = stack.size;
  top = stack.top;
  if (size == 0)
    mas = NULL;
  else 
  {
    mas = new T[size];
    for (int i = 0; i < size; i++)
      mas[i] = stack.mas[i];
  }
}

template<class T>
TStack <T> :: ~TStack() 
{
  top = size = 0;
  delete[] mas;
}

template <class T>
void TStack<T> :: Put(T a) 
{
  if (IsFull()) 
    throw TException("Stack is full.");
  mas[top] = a;
  top++;
}

template <class T>
T TStack<T> :: Get()
{
  if (IsEmpty())
    throw TException("Stack is empty.");
  top--;
  return mas[top];
}

template<class T>
T TStack<T>::TopView()
{
  if (IsEmpty())
    throw TException("Stack is empty.");
  else
  {
    return mas[top - 1];
  }
}

template <class T>
int TStack<T>::GetSize()
{
  return size;
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

template <class T>
TStack<T>& TStack<T>::operator=(const TStack<T> &stack)
{
  if (this != &stack)
  {
    delete[] mas;
    top = stack.top;
    size = stack.size;
    mas = new T[size];
    for (int i = 0; i < size; i++)
      mas[i] = stack.mas[i];
  }
  return *this;
}