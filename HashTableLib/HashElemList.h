#pragma once
#include "../ExceptionLib/Exception.h"
#include <string>

using namespace std;

template <class T>
class TElemL
{
protected:
	string key;
	T data;
	TElemL<T>* next;
public:
	TElemL(string _key = "", T _data = 0, TElemL<T> *_next = NULL);
	TElemL(TElemL &copy);
	~TElemL();

	void SetKey(string _key);
	string GetKey();
	void SetData(T _data);
	T GetData();
	T& GetDataAddress();
	void SetNext(TElemL<T> *elem);
	TElemL<T>* GetNext();

	TElemL<T>& operator=(TElemL &elem);
	bool operator==(TElemL &elem);
	bool operator!=(TElemL<T> &elem);

	friend ostream& operator<<(ostream& out, TElemL<T>& elem)
	{
		out << "Key: " << elem.GetKey() << "\t| ";
		out << "Data: " << elem.GetData() << "\t| ";
		out << "Adress: " << &elem << "\t| ";
		out << "AdressNext: " << elem.GetNext();
		return out;
	}
};

template <class T>
TElemL<T>::TElemL(string _key, T _data, TElemL<T> *_next)
{
	key = _key;
	data = _data;
	next = _next;
}

template <class T>
TElemL<T>::TElemL(TElemL &elem)
{
	key = elem.key;
	data = elem.data;
	next = elem.next;
}

template <class T>
TElemL<T>::~TElemL() 
{
	next = NULL;
}

template <class T>
void TElemL<T>::SetKey(string _key)
{
	key = _key;
}

template <class T>
string TElemL<T>::GetKey()
{
	return key;
}

template <class T>
void TElemL<T>::SetData(T _data)
{
	data = _data;
}

template <class T>
T TElemL<T>::GetData()
{
	return data;
}

template <class T>
T& TElemL<T>::GetDataAddress()
{
	return data;
}

template <class T>
void TElemL<T>::SetNext(TElemL<T> *elem)
{
	if (this == elem)
		throw TException("Error");
	next = elem;
}

template <class T>
TElemL<T>* TElemL<T>::GetNext()
{
	return next;
}

template <class T>
TElemL<T>& TElemL<T>::operator=(TElemL &elem)
{
	if (this != &elem)
	{
		key = elem.key;
		data = elem.data;
		next = elem.next;
	}
	return *this;
}

template <class T>
bool TElemL<T>::operator==(TElemL &elem)
{
	if (key != elem.key)
		return false;
	return true;
}

template <class T>
bool TElemL<T>::operator!=(TElemL<T> &elem)
{
	return !(*this == elem);
}