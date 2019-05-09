#pragma once
#include "../PlexLib/Point.h"

class TCircle
{
protected:
	TPoint* center;
	double radius;
public:
	TCircle(); //����������� �� ���������
	TCircle(const TPoint* point, double rad); //����������� �������������
	TCircle(const double _x, const double _y, const double rad); //����������� �������������
	TCircle(const TCircle& circle); //����������� �����������
	virtual ~TCircle(); //����������

	void SetX(const double _x); //�������� ���������� X ��� ������
	void SetY(const double _y); //�������� ���������� Y ��� ������
	void SetRadius(const double rad); //�������� ������

	double GetX(); //�������� ���������� X ��� ������
	double GetY(); //�������� ���������� Y ��� ������
	double GetRadius(); //�������� ������

	void Show(); //����� ����� �� �������
};