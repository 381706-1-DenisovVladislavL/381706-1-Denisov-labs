#pragma once

#include <iostream>
#include "../VectorLib/Vector.h"

using namespace std;

template <class T>
class TMatrix : public TVector<TVector<T> > {
  //ввод / вывод
  template <class FriendT> friend istream& operator>>(istream &in, TMatrix<FriendT> &MT);
  template <class FriendT> friend ostream& operator<<(ostream &out, const TMatrix<FriendT> &MT);
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix &MT);               // копирование
	TMatrix(const TVector<TVector<T> > &MT);  // преобразование типа
	virtual ~TMatrix<T>();                    // деструктор

	bool operator==(const TMatrix &MT);       // сравнение
	bool operator!=(const TMatrix &MT);       // сравнение
	TMatrix& operator= (const TMatrix &MT);   // присваивание
	TMatrix  operator+ (const TMatrix &MT);   // сложение
	TMatrix  operator- (const TMatrix &MT);   // вычитание
  TMatrix operator* (const TMatrix &MT);    // умножение
};

// онструктор по умолчанию
template <class T>
TMatrix<T>::TMatrix(int s) : TVector<TVector<T> >(s)
{
	if ((s <= 0) || (s > 10000))
		throw TException("Negative or too large size of Matrix.");
  for (int i = 0; i < s; i++)
		this->mas[i] = TVector <T>(s-i);
}

// онструктор копировани€
template <class T> 
TMatrix<T>::TMatrix(const TMatrix<T> &MT) : TVector<TVector<T> >(MT) {}

// онструктор преобразовани€ типа
template <class T> 
TMatrix<T>::TMatrix(const TVector<TVector<T> > &MT) : TVector<TVector<T> >(MT) {}

//деструктор
template <class T>
TMatrix<T>::~TMatrix() {}

//ѕроверка на равенство
template <class T>
bool TMatrix<T>::operator==(const TMatrix<T> &MT) 
{
	return TVector<TVector<T> >::operator==(MT);  //вызываем аналогичный оператор дл€ вектора, в качестве правого операнда передаем матрицу - вектор векторов
}

//ѕроверка на неравенство
template <class T> 
bool TMatrix<T>::operator!=(const TMatrix<T> &MT)
{
	return TVector<TVector<T> >::operator!=(MT); //аналогично равенству
}

//ѕрисваивание
template <class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &MT)
{
	TVector<TVector<T> >::operator=(MT); //аналогично
	return *this;
}

//—ложение
template <class T> 
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &MT)
{
	if (this->size != MT.size)
		throw TException("Addition of matrix of different dimensions.");
	return TVector <TVector<T> > :: operator+(MT);
}

//¬ычитание
template <class T> 
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &MT)
{
	if (this->size != MT.size)
		throw TException("Subtracting of matrix of different dimensions.");
	return TVector <TVector<T> > :: operator-(MT);
}

//”множение
template <class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T> &MT)
{
  if (this->size != MT.size)
    throw TException("Multiplication of matrix of different dimensions.");
  TMatrix <T> temp(this->size);
  for (int i = 0; i < this->size; i++)
    for (int j = i; j < this->size; j++) {
      for (int k = i; k <= j; k++)
        temp.mas[i][j - i] += this->mas[i][k - i] * MT.mas[k][j - k];
    }
  return temp;
}

//¬вод через консоль
template <class FriendT> 
istream& operator>>(istream &in, TMatrix<FriendT> &MT)
{
  for (int i = 0; i < MT.size; i++)
    in >> MT.mas[i];
  return in;
}

//¬ывод через консоль
template <class FriendT> 
ostream & operator<<(ostream &out, const TMatrix<FriendT> &MT)
{
  for (int i = 0; i < MT.size; i++) {
    for (int j = 1; j <= i; j++)
      out << "\t";
    out << MT.mas[i] << endl;
  }
  return out;
}