#pragma once

#include <iostream>
#include "../ExceptionLib/Exception.h"

using namespace std;

template <class T>
class TVector {
  template <class FriendT> friend TVector<FriendT> operator*(FriendT a, const TVector<FriendT> &v);
  template <class FriendT> friend istream& operator>>(istream &is, TVector<FriendT> &v); //ввод вектора через консоль  
  template <class FriendT> friend ostream& operator<<(ostream &os, const TVector<FriendT> &v); //вывод вектора на консоль
protected:
  int size;
  T *mas;
public:
  TVector<T>(int n = 0); 
  TVector<T>(const TVector<T> &v);
  virtual ~TVector<T>();

  int GetSize() const;
  T& operator[](int i); //0-based indexing

  bool operator==(const TVector<T> &v); 
  bool operator!=(const TVector<T> &v);
  TVector& operator=(const TVector<T> &other);

  TVector operator++(); //inc
  TVector operator++(int); //postfix inc
  TVector operator--(); //dec
  TVector operator--(int); //postfix dec

  TVector operator+() const; //unary +
  TVector operator-() const; //unary -
  TVector operator+(const TVector<T> &v); //binary +
  TVector operator-(const TVector<T> &v); //binary -

  T operator*(const TVector<T> &v); //scalar multipl
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
TVector<T>::TVector(const TVector<T> &v) {
  size = v.size;
  if (size == 0)
    mas = NULL;
  else {
    mas = new T[size];
    for (int i = 0; i < size; i++)
      mas[i] = v.mas[i];
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
TVector<T>& TVector<T>::operator=(const TVector<T> &v) {
  if (this == &v) 
    return *this;
  delete[] mas;
  size = v.size;
  mas = new T[size];
  for (int i = 0; i < size; i++)
    (*this)[i] = v.mas[i];
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
TVector<T> TVector<T>::operator+(const TVector<T> &v) {
  if (size != v.size) 
    throw TException("Addition of vectors of different dimensions.");
  TVector<T> temp(size);
  for (int i = 0; i < size; i++)
    temp[i] = (*this)[i] + v.mas[i];
  return temp;
}

template<class T>
TVector<T> TVector<T>::operator-(const TVector<T> &v) {
  if (size != v.size)
    throw TException("Subtracting of vectors of different dimensions.");
  TVector<T> temp(size);
  for (int i = 0; i < size; i++)
    temp[i] = (*this)[i] - v.mas[i];
  return temp;
}

template<class T> 
T TVector<T>::operator*(const TVector <T> &v) {
  if (size != v.size)
    throw TException("Multiplication of vectors of different dimensions.");
  T temp = 0;
  for (int i = 0; i < size; i++)
    temp += (*this)[i] * v.mas[i];
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
TVector<FriendT> operator*(FriendT a, const TVector<FriendT> &v) {
  TVector<FriendT> temp(v.size);
  for (int i = 0; i < v.size; i++)
    temp[i] = v.mas[i] * a;
  return temp;
}

template<class T> 
bool TVector<T>::operator==(const TVector<T> &v){
  if (size == v.size)
  {
    for (int i = 0; i < size; i++)
    {
      if (this->mas[i] != v.mas[i])
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
bool TVector<T>:: operator!=(const TVector<T> &v)
{
  return !(*this == v);
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
istream& operator>>(istream &is, TVector<FriendT> &v) {
  cout << "\nEnter the " << v.size << " coordinates of the vector through the space: ";
  for (int i = 0; i < v.size; i++)
    is >> v.mas[i];
  cout << "Success!";
  return is;
}

template<class FriendT>
ostream& operator<<(ostream &os, const TVector<FriendT> &v) {
  for (int i = 0; i < v.size; i++)
    os << v.mas[i] << "\t";
  return os;
}
