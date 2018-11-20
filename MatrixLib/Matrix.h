#pragma once

#include <iostream>
#include "../VectorLib/Vector.h"

using namespace std;

template <class T>
class TMatrix : public TVector<TVector<T>>{
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix &MT);                    // �����������
	TMatrix(const TVector<TVector<T>> &MT);			// �������������� ����
	bool operator==(const TMatrix &MT) const;      // ���������
	bool operator!=(const TMatrix &MT) const;      // ���������
	TMatrix& operator= (const TMatrix &MT);        // ������������
	TMatrix  operator+ (const TMatrix &MT);        // ��������
	TMatrix  operator- (const TMatrix &MT);        // ���������

	// ���� / �����
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

//����������� �� ���������
template <class T>
TMatrix<T>::TMatrix(int s) : TVector<TVector<T>>(s)
{
	if ((s < 0) || (s > 10000))
		throw 1;
	else
		for (int i = 0; i < s; i++)
			Mas[i] = TVector <T>(s-i); 
}

// ����������� �����������
template <class T> 
TMatrix<T>::TMatrix(const TMatrix<T> &MT) : TVector<TVector<T>>(MT) {}

// ����������� �������������� ����
template <class T> 
TMatrix<T>::TMatrix(const TVector<TVector<T>> &MT) : TVector<TVector<T>>(MT) {}

//�������� �� ���������
template <class T>
bool TMatrix<T>::operator==(const TMatrix<T> &MT) const
{
	return TVector<TVector<T>>::operator==(MT);  //�������� ����������� �������� ��� �������, � �������� ������� �������� �������� ������� - ������ ��������
}

//�������� �� �����������
template <class T> 
bool TMatrix<T>::operator!=(const TMatrix<T> &MT) const
{
	return TVector<TVector<T>>::operator!=(MT); //���������� ���������
}

// ������������
template <class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &MT)
{
	TVector<TVector<T>>::operator=(MT); //����������
	return *this;
}

// ��������
template <class T> 
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &MT)
{
	if (Size != MT.Size)
		throw 1;
	else
		return TVector <TVector<T>> :: operator+(MT);
}

// ���������
template <class T> 
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &MT)
{
	if (TVector<T>::Size != MT.TVector<T>::Size)
		throw 1;
	else
		return TVector <TVector<T>> :: operator-(MT);
}