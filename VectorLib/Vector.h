#pragma once

#include <iostream>
#include "../ExceptionLib/Exception.h"

using namespace std;

template <class T>
class TVector {
  template <class FriendT> friend TVector<FriendT> operator*(FriendT a, const TVector<FriendT> &V);
  template <class FriendT> friend istream& operator>>(istream &is, TVector<FriendT> &V); //ввод вектора через консоль  
  template <class FriendT> friend ostream& operator<<(ostream &os, const TVector<FriendT> &V); //вывод вектора на консоль
protected:
  int size;
T *mas;
public:
  TVector<T>(int n = 0); 
  TVector<T>(const TVector<T> &V);
  virtual ~TVector<T>();

  int GetSize() const;
  T& operator[](int i); //0-based indexing

  bool operator==(const TVector<T> &V); 
  bool operator!=(const TVector<T> &V);
  TVector& operator=(const TVector<T> &other);

  TVector operator++(); //inc
  TVector operator++(int); //postfix inc
  TVector operator--(); //dec
  TVector operator--(int); //postfix dec

  TVector operator+() const; //unary +
  TVector operator-() const; //unary -
  TVector operator+(const TVector<T> &V); //binary +
  TVector operator-(const TVector<T> &V); //binary -

  T operator*(const TVector<T> &V); //scalar multipl
  TVector operator*(T a);
};

template<class T>
TVector<T>::TVector(int n) {
  if (n < 0)
    throw TException("Negative vector size.");
  else
    if (n == 0) {
      size = n;
      mas = NULL;
    }
    else {
      size = n;
      mas = new T[size];
      for (int i = 0; i < size; i++)
        mas[i] = 0;
    }
}

template<class T> 
TVector<T>::TVector(const TVector<T> &V) {
  size = V.size;
  if (size == 0)
    mas = NULL;
  else {
    mas = new T[size];
    for (int i = 0; i < size; i++)
      mas[i] = V.mas[i];
  }
}

template<class T> 
TVector<T>::~TVector() {
  if (size > 0) {
    size = 0;
    delete[] mas;
    mas = NULL;
  }
}

template<class T> 
int TVector<T>::GetSize() const {
  return size;
}

template<class T>
T& TVector<T>::operator[](int i) {
  if ((i < 0) || (i >= size)) 
    throw TException("Out of range.");
  return mas[i];
}

template<class T> 
TVector<T>& TVector<T>::operator=(const TVector<T> &V) {
  if (this == &V) 
    return *this;
  delete[] mas;
  size = V.size;
  mas = new T[size];
  for (int i = 0; i < size; i++)
    (*this)[i] = V.mas[i];
  return *this;
}

template<class T>
TVector<T> TVector<T>::operator+() const {
  TVector<T> temp(*this);
  return temp;
}

template<class T> 
TVector<T> TVector<T>::operator-() const {
  TVector<T> temp(size);
  for (int i = 0; i < size; i++)
    temp[i] = -mas[i];
  return temp;
}

template<class T>
TVector<T> TVector<T>::operator+(const TVector<T> &V) {
  if (size != V.size) 
    throw TException("Addition of vectors of different dimensions.");
  TVector<T> temp(size);
  for (int i = 0; i < size; i++)
    temp[i] = (*this)[i] + V.mas[i];
  return temp;
}

template<class T>
TVector<T> TVector<T>::operator-(const TVector<T> &V) {
  if (size != V.size)
    throw TException("Subtracting of vectors of different dimensions.");
  TVector<T> temp(size);
  for (int i = 0; i < size; i++)
    temp[i] = (*this)[i] - V.mas[i];
  return temp;
}

template<class T> 
T TVector<T>::operator*(const TVector <T> &V) {
  if (size != V.size)
    throw TException("Multiplication of vectors of different dimensions.");
  T temp = 0;
  for (int i = 0; i < size; i++)
    temp += (*this)[i] * V.mas[i];
  return temp;
}

template<class T> 
TVector<T> TVector<T>::operator*(T a) {
  TVector<T> temp(size);
  for (int i = 0; i < size; i++)
    temp[i] = (*this)[i] * a;
  return temp;
}

template<class FriendT> 
TVector<FriendT> operator*(FriendT a, const TVector<FriendT> &V) {
  TVector<FriendT> temp(V.size);
  for (int i = 0; i < V.size; i++)
    temp[i] = V.mas[i] * a;
  return temp;
}

template<class T> 
bool TVector<T>::operator==(const TVector<T> &V) {
  if (size == V.size)
  {
    for (int i = 0; i < size; i++)
    {
      if (this->mas[i] != V.mas[i])
        return 0;
    }
  }
  else
  {
    return 0;
  }
  return 1;
}

template <class T>
bool TVector<T>:: operator!=(const TVector<T> &V)
{
  return !(*this == V);
}

template<class T> 
TVector<T> TVector<T>::operator++() {
  for (int i = 0; i < size; i++)
    mas[i] = mas[i] + 1;
  return *this;
}

template<class T> 
TVector<T> TVector<T>::operator++(int) {
  TVector<T> temp(*this);
  for (int i = 0; i < size; i++)
    mas[i] = mas[i] + 1;
  return temp;
}

template<class T> 
TVector<T> TVector<T>::operator--() {
  for (int i = 0; i < size; i++)
    mas[i] = mas[i] - 1;
  return *this;
}

template<class T> 
TVector<T> TVector<T>::operator--(int) {
  TVector<T> temp(*this);
  for (int i = 0; i < size; i++)
    mas[i] = mas[i] - 1;
  return temp;
}

template<class FriendT>
istream& operator>>(istream &is, TVector<FriendT> &V) {
  cout << "\nEnter the " << V.size << " coordinates of the vector through the space: ";
  for (int i = 0; i < V.size; i++)
    is >> V.mas[i];
  cout << "Success!";
  return is;
}

template<class FriendT>
ostream& operator<<(ostream &os, const TVector<FriendT> &V) {
  for (int i = 0; i < V.size; i++)
    os << V.mas[i] << "\t";
  return os;
}
