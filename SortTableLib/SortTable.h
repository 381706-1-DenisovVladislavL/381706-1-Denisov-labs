#pragma once
#include "../ScanTableLib/ScanTable.h"

#define INSERT_SORT 0
#define SHELL_SORT 1
#define QUICK_SORT 2

template<class T>
class TSortTable
{
protected:
	TElem<T> notFound;
	TElem<T>* mas;
	int size;
	int count;
public:
	TSortTable(int _size = 10);
	TSortTable(string* _keys, T* _data, int _size, const int _sort);
	TSortTable(TSortTable<T> &sorttable);
	~TSortTable();

	int GetSize();
	int GetCount();
	void Resize(int _size);

	int Put(string _key, T _data);
	void Del(string _key);
	TElem<T>& Search(string _key);
	T& operator[](string _key);

	void Print();

	void InsertSort(TTable<T>& table);
	void ShellSort(TTable<T>& table);
	void QuickSort(TTable<T>& table, const int low, const int high);

	friend ostream& operator<<(ostream& out, TSortTable<T>& sorttable)
	{
		out << "Print Table [" << sorttable.count << "/" << sorttable.size << "] \n";
		for (int i = 0; i < sorttable.count; i++)
			out << sorttable.mas[i] << endl;
		return out;
	}
};

template<class T>
TSortTable<T>::TSortTable(int _size)
{
	if (_size <= 0)
		throw TException("Size must be positive!");
	else
	{
		size = _size;
		count = 0;
		notFound.SetKey("NOT_FOUND");
		notFound.SetData(404);
		mas = new TElem<T>[size];
	}
}

template<class T>
TSortTable<T>::TSortTable(string* _keys, T* _data, int _size, const int _sort)
{
	if (_size <= 0)
		throw TException("Size must be positive!");
	TTable<T> table(_size);
	for (int i = 0; i < _size; i++) 
	{
		table.Put(_keys[i], _data[i]);
	}
	size = table.size;
	count = table.count;
	mas = new TElem<T>[size];
	if (_sort == INSERT_SORT)
		TSortTable<T>::InsertSort(table);
	else if (_sort == SHELL_SORT)
		TSortTable<T>::ShellSort(table);
	else if (_sort == QUICK_SORT)
		TSortTable<T>::QuickSort(table, 0, table.count - 1);
	else
		throw TException("Unknown type sort");
	for (int i = 0; i < count; i++)
		mas[i] = table.mas[i];
}


template<class T>
TSortTable<T>::TSortTable(TSortTable<T> &sorttable)
{
	size = sorttable.size;
	count = sorttable.count;
	mas = new TElem<T>[size];
	for (int i = 0; i < size; i++)
		mas[i] = sorttable.mas[i];
}

template <class T>
TSortTable<T>::~TSortTable() 
{
	count = size = 0;
	delete[] mas;
}

template <class T>
int TSortTable<T>::GetSize()
{
	return size;
}

template <class T>
int TSortTable<T>::GetCount()
{
	return count;
}

template<class T>
void TSortTable<T>::Resize(int _size)
{
	if (_size <= size)
		throw TException("Wrong size!");
	TElem<T>* newMas = new TElem<T>[_size];
	for (int i = 0; i < size; i++)
		newMas[i] = mas[i];
	delete[] mas;
	mas = newMas;
	size = _size;
}

template<class T>
int TSortTable<T>::Put(string _key, T _data)
{
	if (size == count)
		Resize(count * 2);
	if (count == 0)
	{
		mas[0].SetKey(_key);
		mas[0].SetData(_data);
		count++;
		return 0;
	}
	int right = count - 1;
	int left = 0;
	int cur = count / 2;
	while (left < right)
	{
		if (mas[cur].GetKey() > _key)
		{
			right = cur - 1;
			cur = ((left + right) / 2);
		}
		else if (mas[cur].GetKey() < _key)
		{
			left = cur + 1;
			cur = ((left + right) / 2);
		}
		else
		{
			throw TException("Such key already exists!");
		}
	}

	if (mas[cur].GetKey() < _key)
		cur++;

	for (int i = count - 1; i >= cur; i--)
		mas[i + 1] = mas[i];
	mas[cur].SetKey(_key);
	mas[cur].SetData(_data);
	count++;
	return cur;
}

template<class T>
void TSortTable<T>::Del(string _key)
{
	int right = count - 1;
	int left = 0;
	int cur = count / 2;
	if (count == 0) return;
	while (left <= right)
	{
		if (mas[cur].GetKey() > _key)
		{
			right = cur - 1;
			cur = ((left + right) / 2);
		}
		else if (mas[cur].GetKey() < _key)
		{
			left = cur + 1;
			cur = ((left + right) / 2);
		}
		else if (mas[cur].GetKey() == _key)
		{
			for (int i = cur; i < count - 1; i++)
				mas[i] = mas[i + 1];
			count--;
			return;
		}
		else 
			return;
	}
}

template<class T>
TElem<T>& TSortTable<T>::Search(string _key)
{
	int right = count - 1;
	int left = 0;
	int cur = count / 2;
	while (left <= right)
	{
		if (mas[cur].GetKey() > _key)
		{
			right = cur - 1;
			cur = ((left + right) / 2);
		}
		else if (mas[cur].GetKey() < _key)
		{
			left = cur + 1;
			cur = ((left + right) / 2);
		}
		else
			return mas[cur];
	}
	return notFound;
}

template<class T>
T& TSortTable<T>::operator[](string _key)
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
void TSortTable<T>::Print()
{
	cout << "Print Table [" << count << "/" << size << "] \n";
	for (int i = 0; i < count; i++)
		cout << mas[i] << endl;
}

template <class T>
void TSortTable<T>::InsertSort(TTable<T>& table)
{
	for (int i = 1; i < table.count; i++)
	{
		TElem<T> temp = table.mas[i];
		int j = i;
		while (j > 0 && table.mas[j - 1].GetKey() > temp.GetKey())
		{
			table.mas[j] = table.mas[j - 1];
			j--;
		}
		table.mas[j] = temp;
	}
}

template <class T>
void TSortTable<T>::ShellSort(TTable<T>& table) 
{
	TElem<T> tmp;
	int i, j, k;
	for (k = table.size / 2; k > 0; k /= 2)
		for (i = k; i < table.size; i++)
		{
			tmp = table.mas[i];
			for (j = i; j >= k; j -= k)
			{
				if (tmp < table.mas[j - k])
					table.mas[j] = table.mas[j - k];
				else
					break;
			}
			table.mas[j] = tmp;
		}
}

template <class T>
void TSortTable<T>::QuickSort(TTable<T>& table, const int low, const int high)
{
	int i = low, j = high;
	TElem<T> d;
	TElem<T> tmp = table.mas[(low + high) / 2];
	while (i <= j)
	{
		for (; table.mas[i].GetKey() < tmp.GetKey(); i++);
		for (; table.mas[j].GetKey() > tmp.GetKey(); j--);
		if (i <= j)
		{
			d = table.mas[i];
			table.mas[i++] = table.mas[j];
			table.mas[j--] = d;
		}
	}
	if (low < j)
		QuickSort(table, low, j);
	if (i < high)
		QuickSort(table, i, high);
}