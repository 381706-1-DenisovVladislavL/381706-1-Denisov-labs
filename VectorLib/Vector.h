#pragma once
#include <iostream>

#include "../ExceptionLib/Exception.h"

using namespace std;

template <class T>
class TVector {
protected:
	int size;
	T *mas;
public:
	TVector<T>(int n = 0); 
	TVector<T>(const TVector<T> &V); //конструктор копирования
	virtual ~TVector<T>(); //деструктор

	int getSize() const; //получение размерности вектора
	T& operator[](int i); //0-based

	bool operator==(const TVector<T> &V); //проверка на равенство
  bool operator!=(const TVector<T> &V);
	TVector& operator=(const TVector<T> &other); //присваивание

	TVector operator++(); //инкремент
	TVector operator++(int); //постфиксный инкремент
	TVector operator--(); //декремент
	TVector operator--(int); //постфиксный декремент

	TVector operator+() const; //унарное сложение
	TVector operator-() const; //унарное вычитание
	TVector operator+(const TVector<T> &V); //сложение векторов
	TVector operator-(const TVector<T> &V); //вычитание векторов

	T operator*(const TVector<T> &V); //скалярное произведение
	TVector operator*(T a); //умножение вектора на число
	template <class FriendT> friend TVector<FriendT> operator*(FriendT a, const TVector<FriendT> &V); //умножение числа на вектор
	
	template <class FriendT> friend istream& operator>>(istream &is, TVector<FriendT> &V); //ввод вектора через консоль	
	template <class FriendT> friend ostream& operator<<(ostream &os, const TVector<FriendT> &V); //вывод вектора на консоль
};

//Конструктор по умолчанию
template<class T>
TVector<T>::TVector(int n) {
	if (n < 0)
		throw "Out of range";
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

//Конструктор копирования
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

//Деструктор
template<class T> 
TVector<T>::~TVector() {
	if (size > 0) {
		size = 0;
		delete[] mas;
		mas = NULL;
	}
}

//Получение размерности вектора
template<class T> 
int TVector<T>::getSize() const {
	return size;
}

//0-based
template<class T>
T& TVector<T>::operator[](int i) {
	if ((i < 0) || (i >= size)) 
		throw "Out of range";
	return mas[i];
}

//Оператор присваивания
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

//Унарное сложение
template<class T>
TVector<T> TVector<T>::operator+() const {
	TVector<T> temp(*this);
	return temp;
}

//Унарное вычитание
template<class T> 
TVector<T> TVector<T>::operator-() const {
	TVector<T> temp(size);
	for (int i = 0; i < size; i++)
		temp[i] = -mas[i];
	return temp;
}

//Сложение векторов
template<class T>
TVector<T> TVector<T>::operator+(const TVector<T> &V) {
	if (size != V.size) 
		throw "Addition of vectors of different dimensions";
	TVector<T> temp(size);
	for (int i = 0; i < size; i++)
		temp[i] = (*this)[i] + V.mas[i];
	return temp;
}

//Вычитание векторов
template<class T>
TVector<T> TVector<T>::operator-(const TVector<T> &V) {
	if (size != V.size)
		throw "Subtracting of vectors of different dimensions";
	TVector<T> temp(size);
	for (int i = 0; i < size; i++)
		temp[i] = (*this)[i] - V.mas[i];
	return temp;
}

//Скалярное произведение векторов
template<class T> 
T TVector<T>::operator*(const TVector <T> &V) {
	if (size != V.size)
		throw "Multiplication of vectors of different dimensions";
	T temp = 0;
	for (int i = 0; i < size; i++)
		temp += (*this)[i] * V.mas[i];
	return temp;
}

//Умножение вектора на число
template<class T> 
TVector<T> TVector<T>::operator*(T a) {
	TVector<T> temp(size);
	for (int i = 0; i < size; i++)
		temp[i] = (*this)[i] * a;
	return temp;
}

//Умножение числа на вектор
template<class FriendT> 
TVector<FriendT> operator*(FriendT a, const TVector<FriendT> &V) {
	TVector<FriendT> temp(V.size);
	for (int i = 0; i < V.size; i++)
		temp[i] = V.mas[i] * a;
	return temp;
}

//Ввод с консоли
template<class FriendT>
istream& operator>>(istream &is, TVector<FriendT> &V) {
	cout << "\nEnter the " << V.size << " coordinates of the vector through the space: ";
	for (int i = 0; i < V.size; i++)
		is >> V.mas[i];
	return is;
}

//Вывод на консоль
template<class FriendT>
ostream& operator<<(ostream &os, const TVector<FriendT> &V) {
	for (int i = 0; i < V.size; i++)
		os << V.mas[i] << "\t";
	return os;
}

//Проверка на равенство
template<class T> 
bool TVector<T>::operator==(const TVector<T> &V) {
  if (size == V.size)
  {
    for (int i = 0; i < size; i++)
    {
      if (this->mas[i] != V.mas[i])
      {
        return 0;
      }
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

//Префиксный инкремент
template<class T> 
TVector<T> TVector<T>::operator++() {
	for (int i = 0; i < size; i++)
		mas[i] = mas[i] + 1;
	return *this;
}

//Постфиксный инкремент
template<class T> 
TVector<T> TVector<T>::operator++(int) {
	TVector<T> temp(*this);
	for (int i = 0; i < size; i++)
		mas[i] = mas[i] + 1;
	return temp;
}

//Префиксный декремент
template<class T> 
TVector<T> TVector<T>::operator--() {
	for (int i = 0; i < size; i++)
		mas[i] = mas[i] - 1;
	return *this;
}

//Постфиксный инкремент
template<class T> 
TVector<T> TVector<T>::operator--(int) {
	TVector<T> temp(*this);
	for (int i = 0; i < size; i++)
		mas[i] = mas[i] - 1;
	return temp;
}
