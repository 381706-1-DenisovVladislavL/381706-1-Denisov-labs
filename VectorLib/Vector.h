#pragma once
#include <iostream>

using namespace std;

template <class T>
class TVector {
private:
	int Size;
	T *Mas;
public:
	TVector<T>():Size(0),Mas(NULL) {} //конструктор по умолчанию
	TVector<T>(int n = 0); //конструктор с одним параметром
	TVector<T>(const TVector<T> &V); //конструктор копировани€
	virtual ~TVector<T>(); //деструктор

	int getSize() const; //получение размерности вектора
	T& operator[](int i); //0-based

	bool operator==(const TVector<T> &V); //проверка на равенство
	TVector& operator=(const TVector<T> &other); //присваивание

	TVector operator++(); //инкремент
	TVector operator++(int); //постфиксный инкремент
	TVector operator--(); //декремент
	TVector operator--(int); //постфиксный декремент

	TVector operator+() const; //унарное сложение
	TVector operator-() const; //унарное вычитание
	TVector operator+(const TVector<T> &V); //сложение векторов
	TVector operator-(const TVector<T> &V); //вычитание векторов

	T operator*(const TVector<T> &V); //скал€рное произведение
	TVector operator*(T a); //умножение вектора на число
	template <class FriendT> friend TVector<FriendT> operator*(FriendT a, const TVector<FriendT> &V); //умножение числа на вектор
	
	template <class FriendT> friend istream& operator>>(istream &is, TVector<FriendT> &V); //ввод вектора через консоль	
	template <class FriendT> friend ostream& operator<<(ostream &os, const TVector<FriendT> &V); //вывод вектора на консоль
};

// онструктор по умолчанию
template<class T> 
TVector<T>::TVector(int n) {
	if (n < 0)
		throw 1;
	else
		if (n == 0) {
			Size = n;
			Mas = NULL;
		}
		else {
			Size = n;
			Mas = new T[Size];
			for (int i = 0; i < Size; i++)
				Mas[i] = 0;
		}
}

// онструктор копировани€
template<class T> 
TVector<T>::TVector(const TVector<T> &V) {
	Size = V.Size;
	if (Size == 0)
		Mas = NULL;
	else {
		Mas = new T[Size];
		for (int i = 0; i < Size; i++)
			Mas[i] = V.Mas[i];
	}
}

//ƒеструктор
template<class T> 
TVector<T>::~TVector() {
	if (Size > 0) {
		Size = 0;
		delete[] Mas;
		Mas = NULL;
	}
}

//ѕолучение размерности вектора
template<class T> 
int TVector<T>::getSize() const {
	return Size;
}

//0-based
template<class T>
T& TVector<T>::operator[](int i) {
	if ((i < 0) || (i >= Size)) 
		throw 1;
	return Mas[i];
}

//ќператор присваивани€
template<class T> 
TVector<T>& TVector<T>::operator=(const TVector<T> &V) {
	if (this == &V) 
		return *this;
	delete[] Mas;
	Size = V.Size;
	Mas = new T[Size];
	for (int i = 0; i < Size; i++)
		(*this)[i] = V.Mas[i];
	return *this;
}

//”нарное сложение
template<class T>
TVector<T> TVector<T>::operator+() const {
	TVector<T> temp(*this);
	return temp;
}

//”нарное вычитание
template<class T> 
TVector<T> TVector<T>::operator-() const {
	TVector<T> temp(Size);
	for (int i = 0; i < Size; i++)
		temp[i] = -Mas[i];
	return temp;
}

//—ложение векторов
template<class T>
TVector<T> TVector<T>::operator+(const TVector<T> &V) {
	if (Size != V.Size) 
		throw 1;
	TVector<T> temp(Size);
	for (int i = 0; i < Size; i++)
		temp[i] = (*this)[i] + V.Mas[i];
	return temp;
}

//¬ычитание векторов
template<class T>
TVector<T> TVector<T>::operator-(const TVector<T> &V) {
	if (Size != V.Size)
		throw 1;
	TVector<T> temp(Size);
	for (int i = 0; i < Size; i++)
		temp[i] = (*this)[i] - V.Mas[i];
	return temp;
}

//—кал€рное произведение векторов
template<class T> 
T TVector<T>::operator*(const TVector <T> &V) {
	if (Size != V.Size)
		throw 1; 
	T temp = 0;
	for (int i = 0; i < Size; i++)
		temp += (*this)[i] * V.Mas[i];
	return temp;
}

//”множение вектора на число
template<class T> 
TVector<T> TVector<T>::operator*(T a) {
	TVector<T> temp(Size);
	for (int i = 0; i < Size; i++)
		temp[i] = (*this)[i] * a;
	return temp;
}

//”множение числа на вектор
template<class FriendT> 
TVector<FriendT> operator*(FriendT a, const TVector<FriendT> &V) {
	TVector<FriendT> temp(V.Size);
	for (int i = 0; i < V.Size; i++)
		temp[i] = V.Mas[i] * a;
	return temp;
}

//¬вод с консоли
template<class FriendT>
istream& operator>>(istream &is, TVector<FriendT> &V) {
	cout << "\nEnter the " << V.Size << " coordinates of the vector through the space: ";
	for (int i = 0; i < V.Size; i++)
		is >> V.Mas[i];
	return is;
}

//¬ывод на консоль
template<class FriendT>
ostream& operator<<(ostream &os, const TVector<FriendT> &V) {
	for (int i = 0; i < V.Size; i++)
		os << V.Mas[i] << "\t";
	return os;
}

//ѕроверка на равенство
template<class T> 
bool TVector<T>::operator==(const TVector<T> &V) {
	if (Size != V.Size) //сравниваем размерности
		return false;
	else {
		T eps = 0.0001;
		for (int i = 0; i < Size; i++)
			if (abs(Mas[i] - V.Mas[i]) < eps) //сравниваем попарно координаты 
				return false;
	}
	return true;
}

//ѕрефиксный инкремент
template<class T> 
TVector<T> TVector<T>::operator++() {
	for (int i = 0; i < Size; i++)
		Mas[i] = Mas[i] + 1;
	return *this;
}

//ѕостфиксный инкремент
template<class T> 
TVector<T> TVector<T>::operator++(int) {
	TVector<T> temp(*this);
	for (int i = 0; i < Size; i++)
		Mas[i] = Mas[i] + 1;
	return temp;
}

//ѕрефиксный декремент
template<class T> 
TVector<T> TVector<T>::operator--() {
	for (int i = 0; i < Size; i++)
		Mas[i] = Mas[i] - 1;
	return *this;
}

//ѕостфиксный инкремент
template<class T> 
TVector<T> TVector<T>::operator--(int) {
	TVector<T> temp(*this);
	for (int i = 0; i < Size; i++)
		Mas[i] = Mas[i] - 1;
	return temp;
}
