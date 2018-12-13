#pragma once

#include <iostream>
#include <iomanip>
#include "../VectorLib/Vector.h"

using namespace std;

template <class T>
class TMatrix : public TVector<TVector<T> > {
  template <class FriendT> friend istream& operator>>(istream &in, TMatrix<FriendT> &mt);
  template <class FriendT> friend ostream& operator<<(ostream &out, const TMatrix<FriendT> &mt);
public:
  TMatrix(int s = 10);
  TMatrix(const TMatrix &mt);
  TMatrix(const TVector<TVector<T> > &mt);
  virtual ~TMatrix<T>();

  bool operator==(const TMatrix &mt);
  bool operator!=(const TMatrix &mt);
  TMatrix& operator= (const TMatrix &mt);
  TMatrix operator+ (const TMatrix &mt);
  TMatrix operator- (const TMatrix &mt);
  TMatrix operator* (const TMatrix &mt);
  TMatrix operator/ (const TMatrix<T> &mt);
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
TMatrix<T>::TMatrix(const TMatrix<T> &mt) : TVector<TVector<T> >(mt) {}

template <class T> 
TMatrix<T>::TMatrix(const TVector<TVector<T> > &mt) : TVector<TVector<T> >(mt) {}

template <class T>
TMatrix<T>::~TMatrix() {}

template <class T>
bool TMatrix<T>::operator==(const TMatrix<T> &mt) 
{
  return TVector<TVector<T> >::operator==(mt);
}

template <class T> 
bool TMatrix<T>::operator!=(const TMatrix<T> &mt)
{
  return TVector<TVector<T> >::operator!=(mt);
}

template <class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &mt)
{
  TVector<TVector<T> >::operator=(mt);
  return *this;
}

template <class T> 
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &mt)
{
  if (this->size != mt.size)
    throw TException("Addition of matrix of different dimensions.");
  return TVector <TVector<T> > :: operator+(mt);
}

template <class T> 
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &mt)
{
  if (this->size != mt.size)
    throw TException("Subtracting of matrix of different dimensions.");
  return TVector <TVector<T> > :: operator-(mt);
}

template <class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T> &mt)
{
  if (this->size != mt.size)
    throw TException("Multiplication of matrix of different dimensions.");
  TMatrix <T> temp(this->size);
  for (int i = 0; i < this->size; i++)
    for (int j = i; j < this->size; j++) {
      for (int k = i; k <= j; k++)
        temp.mas[i][j - i] += this->mas[i][k - i] * mt.mas[k][j - k];
    }
  return temp;
}

template <class T>
TMatrix<T> TMatrix<T>::operator/(const TMatrix<T> &mt)
{
  if (this->size != mt.size)
    throw TException("Division of matrix of different dimensions.");
  double check = 1;
  for (int i = 0; i < size; i++)
    check = check * (*this).mas[i][0];
  if (check < 0.000001)
    throw TException("The determinant of the matrix-right operand is zero.");
  TMatrix <T> copyMt(mt);
  TMatrix <T> resMt(size);
  for (int i = 0; i < size; i++) {
    resMt[i][0] = 1;
    T k = copyMt[i][0];
    for (int j = 0; j < size - i; j++)
    {
      copyMt[i][j] = copyMt[i][j] / k;
      resMt[i][j] = resMt[i][j] / k;
    }
  }

  for (int j = 1; j < size; j++)
  {
    for (int i = 0; i < j; i++)
    {
      T temp = copyMt[i][j - i];
      for (int k = j - i, c = 0; k < size - i; k++)
      {
        copyMt[i][k] = copyMt[i][k] - copyMt[j][c] * temp;
        resMt[i][k] = resMt[i][k] - resMt[j][c++] * temp;
      }
    }
  }
  return ((*this) * resMt);
}

template <class FriendT> 
istream& operator>>(istream &in, TMatrix<FriendT> &mt)
{
  cout << "\nEnter the " << mt.size << " rows of the matrix. Follow the instructions on your console...";
  for (int i = 0; i < mt.size; i++)
    in >> mt.mas[i];
  cout << "\nMatrix successfully introduced!";
  return in;
}

template <class FriendT> 
ostream & operator<<(ostream &out, const TMatrix<FriendT> &mt)
{
  for (int i = 0; i < mt.size; i++) {
    for (int j = 1; j <= i; j++)
      out << "\t";
    out << setprecision(5) << mt.mas[i] << endl;
  }
  return out;
}