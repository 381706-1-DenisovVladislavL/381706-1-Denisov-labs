#pragma once

template <class T>
class TElem {
protected:
  T data; //хранилище данных в списке
  TElem <T>* next; //указатель на следующий элемент списка
public:
  TElem(T _data = 0, TElem <T>* _next = 0);
  TElem(TElem<T> &e);
  virtual ~TElem();

  TElem* GetNext();
  T GetData();
  void Set(T e);
  void SetNext(TElem <T>* n);
};

template <class T>
TElem<T>::TElem(T _data, TElem<T>* _next)
{
  data = _data;
  next = _next;
}

template <class T>
TElem<T>::TElem(TElem<T> &e)
{
  data = e.data;
  next = e.next;
}

template <class T>
TElem<T>::~TElem() {}

template <class T>
T TElem<T>::GetData()
{
  return data;
}

template <class T>
TElem<T>* TElem<T>::GetNext()
{
  return next;
}

template <class T>
void TElem<T>::Set(T _e)
{
  data = _e;
}

template <class T>
void TElem<T>::SetNext(TElem<T>* _n)
{
  next = _n;
}