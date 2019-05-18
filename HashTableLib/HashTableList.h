#pragma once
#include "../HashTableLib/HashElemList.h"

using namespace std;

template<class T>
class THashTableList
{
protected:
	TElemL<T> notFound;
	TElemL<T>** mas;
	int size;
	int count;

	unsigned Hash(string _key);
	void Resize(int _size);
public:
	THashTableList(int _size = 5);
	THashTableList(THashTableList<T> &hashtable);
	~THashTableList();

	int GetSize();
	int GetCount();

	//void Put(string _key, T _data, TElemL<T> *_next);
	void Put(TElemL<T>& elem);
	bool Del(string _key);
	TElemL<T>& Search(string _key);

	bool IsSimple(const int nubmer);

	friend ostream& operator<<(ostream& out, THashTableList<T>& hashtable)
	{
		out << "Print Table [" << hashtable.count << "/" << hashtable.size << "] \n";
		for (int i = 0; i < hashtable.size; i++)
			if (hashtable.mas[i] != &hashtable.notFound)
			{
				TElemL<T> *temp = hashtable.mas[i];
				do
				{
					out << (*temp) << "\n";
					temp = temp->GetNext();
				} while (temp != NULL);
			}
		return out;
	}
};

template <class T>
THashTableList<T>::THashTableList(int _size = 5) 
{
	if (_size <= 0)
		throw TException("Error size");
	count = 0;
	size = _size;
	notFound.SetKey("NOT_FOUND");
	notFound.SetData(404);
	notFound.SetNext(NULL);
	mas = new TElemL<T>*[size];
	for (int i = 0; i < size; i++)
		mas[i] = &notFound;
}

template <class T>
THashTableList<T>::THashTableList(THashTableList<T> &hashtable) 
{
	count = hashtable.count;
	size = hashtable.size;
	mas = new TElemL<T>*[size];
	for (int i = 0; i < size; i++)
	{
		if (*hashtable.mas[i] == notFound)
			mas[i] = &notFound;
		else 
		{
			TElemL<T> *iter1 = hashtable.mas[i], *iter2;
			mas[i] = new TElemL<T>(*hashtable.mas[i]);
			iter2 = mas[i];
			while (iter1->GetNext() != NULL)
			{
				iter2->SetNext(new TElemL<T>(*(iter1->GetNext()))); 
				iter1 = iter1->GetNext();
				iter2 = iter2->GetNext();
			}
		}
	}
}

template <class T>
THashTableList<T>::~THashTableList() 
{

}
 
template <class T>
unsigned THashTableList<T>::Hash(string _key)
{
	unsigned int hashvalue = 0;
	for (unsigned i = 0; i < _key.length(); i++)
		hashvalue += (unsigned)(_key[i]);
	return hashvalue;
}

template <class T>
void THashTableList<T>::Resize(int _size)
{
	if (_size <= size)
		throw TException("Error size");
	while (!IsSimple(_size))
		_size++;
	TElemL<T>** tmp = new TElemL<T>*[_size];
	for (int i = 0; i < size; i++)
		tmp[i] = mas[i];
	for (int i = size; i < _size; i++)
		tmp[i] = &notFound;
	size = _size;
	delete[] mas;
	mas = tmp;
}

template <class T>
bool THashTableList<T>::IsSimple(const int number)
{
	for (int i = 2; i < number / 2; i++)
		if (number % i == 0)
			return false;
	return true;
}

template <class T>
int THashTableList<T>::GetSize()
{
	return size;
}

template <class T>
int THashTableList<T>::GetCount()
{
	return count;
}

template <class T>
void THashTableList<T>::Put(TElemL<T>& elem)
{
	unsigned hashvalue = Hash(elem.GetKey());
	if (count == size)
		Resize(count * 2);
	if (hashvalue > size)
		Resize(hashvalue + 10);
	if (mas[hashvalue] == &notFound)
	{
		mas[hashvalue] = new TElemL<T>(elem);
		count++;
	}
	else
	{
		TElemL<T> *tmp = new TElemL<T>(elem);
		tmp->SetNext(mas[hashvalue]);
		mas[hashvalue] = tmp;
		count++;
	}
}

template <class T>
bool THashTableList<T>::Del(string _key)
{
	unsigned hashvalue = Hash(_key);
	if (hashvalue > size)
		throw TException("Error");
	TElemL<T> *iter = mas[hashvalue];
	TElemL<T> *par = NULL;
	if (mas[hashvalue] == &notFound)
	{
		return false;
	}
	else if (mas[hashvalue]->GetNext() == NULL)
	{
		delete mas[hashvalue];
		count--;
		mas[hashvalue] = &notFound;
		return true;
	}
	else
	{
		while ((iter->GetNext() != NULL) && (iter->GetKey() != _key))
		{
			par = iter;
			iter = iter->GetNext();
		}
		if (iter->GetKey() == _key)
		{
			if (par != NULL)
				par->SetNext(iter->GetNext());
			else
				mas[hashvalue] = iter->GetNext();
			delete iter;
			count--;
			return true;
		}
	}
	return false;
}

template <class T >
TElemL<T>& THashTableList<T>::Search(string _key) 
{
	unsigned hashvalue = Hash(_key);
	if (mas[hashvalue]->GetKey() == _key)
	{
		return (*mas[hashvalue]);
	}
	else if (mas[hashvalue]->GetNext() != NULL)
	{
		TElemL<T> *iter = mas[hashvalue];
		while (iter != NULL)
		{
			if (iter->GetKey() == _key)
				return *iter;
			iter = iter->GetNext();
		}
	}
	return notFound;
}