#pragma once
#include "../ScanTableLib/ScanElem.h"

template <class T>
class TTable
{
protected:
	TElem<T> notFound;
	TElem<T> *mas;
	int size, count;
public:
	TTable(int _size = 10);
	TTable(TTable &table);

	int GetSize();
	int GetCount();

	void Put(string _key, T _data);
	void Del(string _key);
	TElem<T>& Search(string _key);

	T& operator[](string _key);

	friend ostream& operator<<(ostream& out, TTable<T>& table)
	{
		out << "Print Table [" << table.count << "/" << table.size <<  "] \n";
		for (int i = 0; i < table.count; i++)
			out << table.mas[i] << endl;
		return out;
	}
};

template <class T>
TTable<T>::TTable(int _size)
{
	if (_size < 0)
		throw TException("Error! Size must be positive!");
	else if (_size == 0)
	{
		size = 0;
		count = 0;
		notFound.SetKey("NOT_FOUND");
		notFound.SetData(404);
		mas = NULL;
	}
	else
	{
		size = _size;
		count = 0;
		notFound.SetKey("NOT_FOUND");
		notFound.SetData(404);
		mas = new TElem<T>[size];
	}
}

template <class T>
TTable<T>::TTable(TTable &table)
{
	size = table.size;
	count = table.count;
	mas = new TElem<T>[size];
	for (int i = 0; i < size; i++)
		mas[i] = table.mas[i];
}

template <class T>
void TTable<T>::Put(string _key, T _data)
{
	if (size == count)
		throw TException("Error! Table is full!");
	else
	{
		mas[count].SetKey(_key);
		mas[count].SetData(_data);
		count++;
	}
}

template <class T>
void TTable<T>::Del(string _key)
{
	if (count == 0)
		throw TException("Error! Table is empty!");
	else
	{
		TElem<T>& tmp = Search(_key);
		if (!(tmp == notFound))
			tmp = notFound;
	}
}

template <class T>
TElem<T>& TTable<T>::Search(string _key)
{
	for (int i = 0; i < count; i++)
		if (_key == mas[i].GetKey())
			return mas[i];
	return notFound;
}

template <class T>
T& TTable<T>::operator[](string _key)
{
	TElem<T>& tmp = Search(_key);
	if (tmp == notFound)
	{
		Put(_key, 0);
		return mas[count - 1].GetDataAddress();
	}
	return tmp.GetDataAddress();
}

template <class T>
int TTable<T>::GetSize()
{
	return size;
}

template <class T>
int TTable<T>::GetCount()
{
	return count;
}
