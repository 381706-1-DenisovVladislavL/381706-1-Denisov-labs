#pragma once
#include "../HashTableLib/HashElem.h"

using namespace std;

template<class T>
class THashTable
{
protected:
	TElem<T> notFound;
	TElem<T>* mas;
	int size;
	int count;
	const int m;

	unsigned Hash(string _key);
	void Resize(int _size);
public:
	THashTable(int _size = 5);
	THashTable(THashTable<T> &hashtable);
	~THashTable();

	int GetSize();
	int GetCount();
	TElem<T> GetNotFound();

	void Put(string _key, T _data);
	void Put(TElem<T>& elem);
	bool Del(string _key);
	TElem<T>& Search(string _key);

	bool IsSimple(const int nubmer);

	friend ostream& operator<<(ostream& out, THashTable<T>& hashtable)
	{
		out << "Print Table [" << hashtable.count << "/" << hashtable.size << "] \n";
		for (int i = 0; i < hashtable.count; i++)
			out << hashtable.mas[i] << endl;
		return out;
	}
};

template <class T>
THashTable<T>::THashTable(int _size):m(2)
{
	if (_size <= 0)
		throw TException("Error size");
	count = 0;
	size = _size;
	mas = new TElem<T>[size];
	for (int i = 0; i < size; i++)
		mas[i] = notFound;
}

template <class T>
THashTable<T>::THashTable(THashTable<T>& hashtable):m(hashtable.m)
{
	count = hashtable.count;
	size = hashtable.size;
	mas = new TElem<T>[size];
	for (int i = 0; i < size; i++)
		mas[i] = hashtable.mas[i];
}

template <class T>
THashTable<T>::~THashTable()
{
	count = size = 0;
	delete[] mas;
}

template <class T>
int THashTable<T>::GetSize()
{
	return size;
}

template <class T>
int THashTable<T>::GetCount()
{
	return count;
}

template <class T>
TElem<T> THashTable<T>::GetNotFound() 
{
	return notFound;
}

template <class T>
void THashTable<T>::Put(string _key, T data)
{
	if (count == size)
		Resize(count * 2);
	int i = Hash(_key);
	if (i > size)
		Resize(i + 10);
	while (mas[i] != notFound)
		i = (i + m) % size;
	mas[i].SetKey(_key);
	mas[i].SetData(data);
	count++;
}

template <class T>
void THashTable<T>::Put(TElem<T>& elem)
{
	if (count == size)
		Resize(count * 2);
	int i = Hash(elem.GetKey());
	if (i > size)
		Resize(i + 10);
	while (mas[i] != notFound)
		i = (i + m) % size;
	mas[i] = elem;
	count++;
}

template <class T>
bool THashTable<T>::Del(string _key)
{
	int i = Hash(_key);
	if (i > size)
		throw TException("Error");
	while (mas[i].GetKey() != _key)
	{
		if (mas[i] == notFound)
			return false;
		i = (i + m) % size;
	}
	mas[i] = notFound;
	return true;
}

template <class T>
TElem<T>& THashTable<T>::Search(string key)
{
	int i = Hash(key);
	while (mas[i].GetKey() != key)
	{
		i = (i + m) % size;
		if (mas[i] == notFound)
			break;
	}
	return mas[i];
}

template <class T>
unsigned THashTable<T>::Hash(string _key)
{
	unsigned int hashvalue = 0;
	for (unsigned i = 0; i < _key.length(); i++)
		hashvalue += (unsigned)(_key[i]);
	return hashvalue;
}

template <class T>
void THashTable<T>::Resize(int _size)
{
	if (_size <= size)
		throw TException("Error size");
	while (!IsSimple(_size))
		_size++;
	TElem<T>* tmp = new TElem<T>[_size];
	for (int i = 0; i < size; i++)
		tmp[i] = mas[i];
	for (int i = size; i < _size; i++)
		tmp[i] = notFound;
	size = _size;
	delete[] mas;
	mas = tmp;
}

template <class T>
bool THashTable<T>::IsSimple(const int number)
{
	for (int i = 2; i < number / 2; i++)
		if (number % i == 0)
			return false;
	return true;
}