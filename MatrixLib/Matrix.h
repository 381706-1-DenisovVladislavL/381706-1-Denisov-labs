#pragma once

#include <iostream>
#include "../VectorLib/Vector.h"

using namespace std;

template <class T>
class TMatrix : public TVector<TVector<T>>{
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix &MT);                    // копирование
	TMatrix(const TVector<TVector<T>> &MT);			// преобразование типа
	bool operator==(const TMatrix &MT) const;      // сравнение
	bool operator!=(const TMatrix &MT) const;      // сравнение
	TMatrix& operator= (const TMatrix &MT);        // присваивание
	TMatrix  operator+ (const TMatrix &MT);        // сложение
	TMatrix  operator- (const TMatrix &MT);        // вычитание

	// ввод / вывод
	template <class FriendT> friend istream& operator>>(istream &in, TMatrix<FriendT> &MT)
	{
		for (int i = 0; i < MT.Size; i++)
			in >> MT.Mas[i];
		return in;
	}
	
	template <class FriendT>  friend ostream & operator<<(ostream &out, const TMatrix<FriendT> &MT)
	{
		for (int i = 0; i < MT.Size; i++) {
			for (int j = 1; j <= i; j++)
				out << "\t";
			out << MT.Mas[i] << endl;
		}
		return out;
	}
};

//конструктор по умолчанию
template <class T>
TMatrix<T>::TMatrix(int s) : TVector<TVector<T>>(s)
{
	if ((s < 0) || (s > 10000))
		throw 1;
	else
		for (int i = 0; i < s; i++)
			Mas[i] = TVector <T>(s-i); 
}

// конструктор копирования
template <class T> 
TMatrix<T>::TMatrix(const TMatrix<T> &MT) : TVector<TVector<T>>(MT) {}

// конструктор преобразования типа
template <class T> 
TMatrix<T>::TMatrix(const TVector<TVector<T>> &MT) : TVector<TVector<T>>(MT) {}

//проверка на равенство
template <class T>
bool TMatrix<T>::operator==(const TMatrix<T> &MT) const
{
	return TVector<TVector<T>>::operator==(MT);  //вызываем аналогичный оператор для вектора, в качестве правого операнда передаем матрицу - вектор векторов
}

//проверка на неравенство
template <class T> 
bool TMatrix<T>::operator!=(const TMatrix<T> &MT) const
{
	return TVector<TVector<T>>::operator!=(MT); //аналогично равенству
}

// присваивание
template <class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &MT)
{
	TVector<TVector<T>>::operator=(MT); //аналогично
	return *this;
}

// сложение
template <class T> 
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &MT)
{
	if (Size != MT.Size)
		throw 1;
	else
		return TVector <TVector<T>> :: operator+(MT);
}

// вычитание
template <class T> 
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &MT)
{
	if (TVector<T>::Size != MT.TVector<T>::Size)
		throw 1;
	else
		return TVector <TVector<T>> :: operator-(MT);
}