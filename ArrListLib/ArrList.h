#pragma once

#include "../ExceptionLib/Exception.h"
#include "../QueueLib/Queue.h"

template <class T>
class TArrList {
private:
  T* mas;
  int *nextInd; //Массив индексов, указывающих на следюущий элемент списка
  int *prevInd; //Массив индексов, указывающих на предыдущий элемент списка
  int size; //Максимальный размер списка
  int count; //Текущее количество элементов в списке
  int start; //Индекс первого элемента списка
  int finish; //Индекс последнего элемента списка
  TQueue <int> freeElem; //Очередь свободных элементов - для заполнения "пустых" ячеек в массиве, 
                         //оставшихся после удаления элемента
public:
  TArrList(int _size = 10); //Конструктор с параметром
  TArrList(TArrList<T> &A); //Конструктор копирования
  void PushStart(T elem); //Положить в начало списка
  void PushFinish(T elem);	//Положить в конец списка 
  T PullStart();	//Забрать из начала списка с удалением
  T PullFinish();		//Забрать из конца списка с удалением
  bool IsFull();	//Проверка на полноту
  bool IsEmpty();	//Проверка на пустоту
};

//Конструктор с параметром
template <class T>
TArrList<T>::TArrList(int _size) : freeElem(_size)
{
  if (_size <= 0)
    throw TException("Negative size argument when creating a list.");
  size = _size;
  count = 0;
  start = -1;
  finish = -1;
  mas = new T[size];
  nextInd = new int[size];
  prevInd = new int[size];
  for (int i = 0; i < size; i++) 
  {
    nextInd[i] = -2;
    prevInd[i] = -2;
    freeElem.Put(i);
  }
}

//Конструктор копирования
template <class T>
TArrList<T>::TArrList(TArrList<T> &A)
{
  start = A.start;
  finish = A.finish;
  size = A.size;
  count = A.count;
  mas = new T[size];
  nextInd = new int[size];
  prevInd = new int[size];
  freeElem = A.freeElem;
  for (int i = 0; i < size; i++)
  {
    mas[i] = A.mas[i];
    nextInd[i] = A.nextInd[i];
    prevInd[i] = A.prevInd[i];
  }
}

//Положить в начало списка
template <class T>
void TArrList<T>::PushStart(T elem)
{
  if (IsFull())
    throw TException("List is full.");
  int ifree = freeElem.Get();
  mas[ifree] = elem;
  nextInd[ifree] = start;
  if (start != -1)
    prevInd[start] = ifree;
  else
    finish = ifree;
  start = ifree;
  count++;
}

//Положить в конец списка
template <class T>
void TArrList<T>::PushFinish(T elem)
{
  if (IsFull())
    throw TException("List is full.");
  int ifree = freeElem.Get();
  mas[ifree] = elem;
  if (finish != -1)
    nextInd[finish] = ifree;
  else
  {
    start = ifree;
    prevInd[ifree] = -1;
  }
  prevInd[ifree] = finish;
  finish = ifree;
  count++;
}

//Взять из начала списка с удалением
template <class T>
T TArrList<T>::PullStart()
{
  if (IsEmpty())
    throw TException("List is empty.");
  T elem = mas[start];
  int newstart = nextInd[start];
  freeElem.Put(start);
  nextInd[start] = prevInd[start] = -2;
  if (newstart != -1)
    prevInd[newstart] = -1;
  count--;
  start = newstart;
  return elem;
}

//Взять из конца списка с удалением
template <class T>
T TArrList<T>::PullFinish()
{
  if (IsEmpty())
    throw TException("List is empty.");
  T elem = mas[finish];
  int newFinish = prevInd[finish];
  prevInd[finish] = nextInd[finish] = -2;
  freeElem.Put(finish);
  finish = newFinish;
  if (newFinish != -1)
    nextInd[newFinish] = -1;
  else
    start = -1;
  count--;
  return elem;
}

//Проверка на полноту
template <class T>
bool TArrList<T>::IsFull()
{
  if (count == size)
    return true;
  else
    return false;
}

//Проверка на пустоту
template <class T>
bool TArrList<T>::IsEmpty()
{
  if (count == 0)
    return true;
  else
    return false;
}