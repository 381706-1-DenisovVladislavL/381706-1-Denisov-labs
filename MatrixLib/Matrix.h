#pragma once

#include <iostream>
#include "../VectorLib/Vector.h"

using namespace std;

template <class T>
class TMatrix : public TVector<TVector<T> > {
  template <class FriendT> friend istream& operator>>(istream &in, TMatrix<FriendT> &MT);
  template <class FriendT> friend ostream& operator<<(ostream &out, const TMatrix<FriendT> &MT);
public:
  TMatrix(int s = 10);
  TMatrix(const TMatrix &MT);
  TMatrix(const TVector<TVector<T> > &MT);
  virtual ~TMatrix<T>();

  bool operator==(const TMatrix &MT);
  bool operator!=(const TMatrix &MT);
  TMatrix& operator= (const TMatrix &MT);
  TMatrix  operator+ (const TMatrix &MT);
  TMatrix  operator- (const TMatrix &MT);
  TMatrix operator* (const TMatrix &MT);
};

template <class T>
TMatrix<T>::TMatrix(int s) : TVector<TVector<T> >(s)
{
  if ((s <= 0) || (s > 10000))
    throw TException("Negative or too large size of Matrix.");
  for (int i = 0; i < s; i++)
    this->mas[i] = TVector <T>(s-i);
}

template <class T> 
TMatrix<T>::TMatrix(const TMatrix<T> &MT) : TVector<TVector<T> >(MT) {}

template <class T> 
TMatrix<T>::TMatrix(const TVector<TVector<T> > &MT) : TVector<TVector<T> >(MT) {}

template <class T>
TMatrix<T>::~TMatrix() {}

template <class T>
bool TMatrix<T>::operator==(const TMatrix<T> &MT) 
{
  return TVector<TVector<T> >::operator==(MT);
}

template <class T> 
bool TMatrix<T>::operator!=(const TMatrix<T> &MT)
{
  return TVector<TVector<T> >::operator!=(MT);
}

template <class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &MT)
{
  TVector<TVector<T> >::operator=(MT);
  return *this;
}

template <class T> 
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &MT)
{
  if (this->size != MT.size)
    throw TException("Addition of matrix of different dimensions.");
  return TVector <TVector<T> > :: operator+(MT);
}

template <class T> 
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &MT)
{
  if (this->size != MT.size)
    throw TException("Subtracting of matrix of different dimensions.");
  return TVector <TVector<T> > :: operator-(MT);
}

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

template <class FriendT> 
istream& operator>>(istream &in, TMatrix<FriendT> &MT)
{
  cout << "\nEnter the " << MT.size << " rows of the matrix. Follow the instructions on your console...";
  for (int i = 0; i < MT.size; i++)
    in >> MT.mas[i];
  cout << "\nMatrix successfully introduced!";
  return in;
}

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