#pragma once
#include <iostream>

using namespace std;

template <class T>
class TVector {
private:
	int Size;
	T *Mas;
public:
	TVector() :Size(0),Mas(NULL) {} //����������� �� ���������
	TVector(int n = 0); //����������� � ����� ����������
	TVector(const TVector<T> &V); //����������� �����������
	virtual ~TVector(); //����������

	int getSize() const; //��������� ����������� �������
	T& operator[](int i); //0-based

	bool operator==(const TVector<T> &V); //�������� �� ���������
	TVector& operator=(const TVector<T> &other); //������������

	TVector operator++(); //���������
	TVector operator++(int); //����������� ���������
	TVector operator--(); //���������
	TVector operator--(int); //����������� ���������

	TVector operator+() const; //������� ��������
	TVector operator-() const; //������� ���������
	TVector operator+(const TVector<T> &V); //�������� ��������
	TVector operator-(const TVector<T> &V); //��������� ��������

	T operator*(const TVector<T> &V); //��������� ������������
	TVector operator*(T a); //��������� ������� �� �����
	template <typedef T> friend TVector<T> operator*(T a, const TVector<T> &V); //��������� ����� �� ������
	
	template <typedef T> friend istream& operator>>(istream &is, TVector<T> &V); //���� ������� ����� �������	
	template <typedef T> friend ostream& operator<<(ostream &os, const TVector<T> &V); //����� ������� �� �������
};

//����������� �� ���������
template<class T> 
TVector<T> :: TVector<T>(int n) {
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

//����������� �����������
template<class T> 
TVector<T> :: TVector(const TVector<T> &V) {
	Size = Size.V;
	if (Size == 0)
		Mas = NULL;
	else {
		Mas = new T[Size];
		for (int i = 0; i < Size; i++)
			Mas[i] = V.Mas[i];
	}
}

//����������
template<class T> 
TVector<T> :: ~TVector() {
	if (Size > 0) {
		Size = 0;
		delete[] Mas;
		Mas = NULL;
	}
}

//��������� ����������� �������
template<class T> 
int TVector<T> :: getSize() const {
	return Size;
}

//0-based
template<class T>
T& TVector<T> :: operator[](int i) {
	if ((i < 0) || (i >= Size)) 
		throw 1;
	return Mas[i];
}

//�������� ������������
template<class T> 
TVector<T>& TVector<T> :: operator=(const TVector<T> &V) {
	if (this == &V) 
		return *this;
	delete[] Mas;
	Size = V.Size;
	Mas = new T[Size];
	for (int i = 0; i < Size; i++)
		(*this)[i] = V.Mas[i];
	return *this;
}

//������� ��������
template<class T>
TVector<T> TVector<T> :: operator+() const {
	TVector<T> temp(*this);
	return temp;
}

//������� ���������
template<class T> 
TVector<T> TVector<T> :: operator-() const {
	TVector<T> temp(Size);
	for (int i = 0; i < Size; i++)
		temp[i] = -Mas[i];
	return temp;
}

//�������� ��������
template<class T>
TVector<T> TVector<T> :: operator+(const TVector<T> &V) {
	if (Size != V.Size) 
		throw 1;
	TVector<T> temp(N);
	for (int i = 0; i < Size; i++)
		temp[i] = (*this)[i] + V.Mas[i];
	return temp;
}

//��������� ��������
template<class T>
TVector<T> TVector<T> :: operator-(const TVector<T> &V) {
	if (Size != V.Size)
		throw 1;
	vector<T> temp(N);
	for (int i = 0; i < N; i++)
		temp[i] = (*this)[i] - V.Mas[i];
	return temp;
}

//��������� ������������ ��������
template<class T> 
T TVector<T> :: operator*(const TVector <T> &V) {
	if (Size != V.Size)
		throw 1; 
	T temp = 0;
	for (int i = 0; i < Size; i++)
		temp += (*this)[i] * V.Mas[i];
	return temp;
}

//��������� ������� �� �����
template<class T> 
TVector<T> TVector<T> :: operator*(T a) {
	TVector<T> temp(Size);
	for (int i = 0; i < Size; i++)
		temp[i] = (*this)[i] * a;
	return temp;
}

//��������� ����� �� ������
template<class T> 
TVector<T> operator*(T a, const TVector<T> &V) {
	TVector<T> temp(V.Size);
	for (int i = 0; i < V.Size; i++)
		temp[i] = V.Mas[i] * a;
	return temp;
}

//���� � �������
template<class T> 
istream& operator>>(istream &is, TVector<T> &V) {
	cout << "\nEnter the " << V.Size << " coordinates of the vector through the space: ";
	for (int i = 0; i < V.Size; i++)
		is >> V.Mas[i];
	return is;
}

//����� �� �������
template<class T> 
ostream& operator<<(ostream &os, const TVector<T> &V) {
	for (int i = 0; i < V.Size; i++)
		os << V.Mas[i] << "\t";
	return os;
}

//�������� �� ���������
template<class T> 
bool TVector<T> :: operator==(const TVector<T> &V) {
	if (Size != V.Size) //���������� �����������
		return false;
	else
		T eps = 0.0001;
		for (int i = 0; i < Size; i++)
			if (abs(Mas[i] - V.Mas[i]) < eps) //���������� ������� ���������� 
				return false;
	return true;
}

//���������� ���������
template<class T> 
TVector<T> TVector<T> :: operator++() {
	for (int i = 0; i < Size; i++)
		Mas[i] = Mas[i] + 1;
	return *this;
}

//����������� ���������
template<class T> 
TVector<T> TVector<T> :: operator++(int) {
	TVector<T> temp(*this);
	for (int i = 0; i < Size; i++)
		Mas[i] = Mas[i] + 1;
	return temp;
}

//���������� ���������
template<class T> 
TVector<T> TVector<T> :: operator--() {
	for (int i = 0; i < Size; i++)
		Mas[i] = Mas[i] - 1;
	return *this;
}

//����������� ���������
template<class T> 
TVector<T> TVector<T>::operator--(int) {
	TVector<T> temp(*this);
	for (int i = 0; i < Size; i++)
		Mas[i] = Mas[i] - 1;
	return temp;
}
