#pragma once

#include "Stack.h"

template <class T>
class TQueue : public TStack <T> {
protected:
  int start;
  int count;
public:
  TQueue(int n = 0);
  TQueue(TQueue <T> &Q);
  virtual ~TQueue();

  void Put(T A);
  T Get();
  bool IsFull();
  bool IsEmpty();
};

template <class T>
TQueue<T>::TQueue(int n) : TStack<T>(n) { start = 0; count = 0; }

template <class T>
TQueue<T>::TQueue(TQueue<T> &Q) : TStack<T>(Q) { start = Q.start; count = Q.count; }

template <class T>
TQueue<T>::~TQueue() {}

template <class T>
void TQueue<T>::Put(T A) {
  if (IsFull()) 
    throw 1;
  else {
    TStack<T>::mas[start] = A;
    start = (start + 1) % TStack<T>::size;
    count++;
  }  
}

template <class T>
T TQueue<T>::Get() {
  if (IsEmpty()) 
    throw 1;
  else {
    T temp = TStack<T>::mas[TStack<T>::top];
    TStack<T>::top = (TStack<T>::top + 1) % TStack<T>::size;
    count--;
    return temp;
  }
}

template <class T>
bool TQueue<T>::IsFull() {
  if (count == TStack<T>::size)
    return true;
  else
    return false;
}

template <class T>
bool TQueue<T>::IsEmpty() {
  if (count == 0)
    return true;
  else 
    return false;
}