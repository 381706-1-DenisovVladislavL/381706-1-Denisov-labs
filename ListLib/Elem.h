#pragma once

template <class T>
class TElem {
protected:
	T elem; //хранилище данных в списке
	TElem <T>* next; //указатель на следующий элемент списка
public:
	TElem(T _elem = 0, TElem <T>* _n = 0);
	TElem(TElem<T> &E);
	virtual ~TElem();
	TElem* GetNext();
	T Get();
	void Set(T e);
	void SetNext(TElem <T>* n);
};

template <class T>
TElem<T>::TElem(T _e, TElem<T>* _n)
{
	elem = _e;
	if (_n == 0)
		next = 0;
	else
		next = _n;
}

template <class T>
TElem<T>::TElem(TElem<T> &E)
{
	elem = E.elem;
	next = E.next;
}

template <class T>
TElem<T>::~TElem() {}

template <class T>
T TElem<T>::Get()
{
	return elem;
}

template <class T>
TElem<T>* TElem<T>::GetNext()
{
	return next;
}
template <class T>
void TElem<T>::Set(T _e)
{
	elem = _e;
}

template <class T>
void TElem<T>::SetNext(TElem<T>* _n)
{
	next = _n;
}