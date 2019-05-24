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

	void Put(string _key, T _data);
	void Put(TElem<T>& elem);
	bool Del(string _key);
	TElem<T>& Search(string _key);

	bool IsSimple(const int nubmer);

	friend ostream& operator<<(ostream& out, THashTable<T>& hashtable)
	{
		out << "Print Table [" << hashtable.count << "/" << hashtable.size << "] \n";
		for (int i = 0; i < hashtable.size; i++)
			if (hashtable.mas[i] != hashtable.notFound)
				out << "Hash: " << hashtable.Hash(hashtable.mas[i].GetKey()) << "\t| " << hashtable.mas[i] << endl;
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
	notFound.SetKey("NOT_FOUND");
	notFound.SetData(404);
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
void THashTable<T>::Put(string _key, T data)
{
	if (count == size)
		Resize(count * 2);
	unsigned hashvalue = Hash(_key);
	if (hashvalue > (unsigned)size)
		Resize(hashvalue + 10);
	while (mas[hashvalue] != notFound)
		hashvalue = (hashvalue + m) % size;
	mas[hashvalue].SetKey(_key);
	mas[hashvalue].SetData(data);
	count++;
}

template <class T>
void THashTable<T>::Put(TElem<T>& elem)
{
	if (count == size)
		Resize(count * 2);
	unsigned hashvalue = Hash(elem.GetKey());
	if (hashvalue > (unsigned)size)
		Resize(hashvalue + 10);
	while (mas[hashvalue] != notFound)
		hashvalue = (hashvalue + m) % size;
	mas[hashvalue] = elem;
	count++;
}

template <class T>
bool THashTable<T>::Del(string _key)
{
	unsigned hashvalue = Hash(_key);
	unsigned start = hashvalue;
	if (hashvalue > (unsigned)size)
		return false;
	do 
	{
		hashvalue = (hashvalue + m) % size;
	} while ((mas[hashvalue].GetKey() != _key) && (hashvalue != start));
	if (mas[hashvalue] != notFound)
	{
		mas[hashvalue] = notFound;
		count--;
		return true;
	}
	else
		return false;
}

template <class T>
TElem<T>& THashTable<T>::Search(string _key)
{
	unsigned hashvalue = Hash(_key);
	unsigned start = hashvalue;
	if (hashvalue > (unsigned)size)
		return notFound;
	do 
	{
		hashvalue = (hashvalue + m) % size;
	} while ((mas[hashvalue].GetKey() != _key) && (hashvalue != start));
	if (mas[hashvalue] != notFound)
	{
		return mas[hashvalue];
	}
	else
		return notFound;
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