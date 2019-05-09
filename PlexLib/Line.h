#pragma once
#include "../PlexLib/Point.h"

class TLine
{
protected:
	TPoint* point1; //��������� �� ���� �����
	TPoint* point2; //��������� �� ������ �����
	bool del_flag_1; //����, ����������� �������� ����� �����
	bool del_flag_2; //����, ����������� �������� ������ �����
public:
	TLine();
	TLine(const TPoint* _point1, const TPoint* _point2); //����������� ������������� �� ���� �����
	TLine(const double x1, const double y1, const double x2, const double y2); //����������� ������������ �� ��������� ���� �����
	TLine(const TLine& line); //����������� �����������
	virtual ~TLine(); //����������

	void SetX1(const double _x1); //�������� ���������� X ������ �����
	void SetY1(const double _y1); //�������� ���������� Y ������ �����
	void SetX2(const double _x2); //�������� ���������� X ������� �����
	void SetY2(const double _y2); //�������� ���������� Y ������� �����
	void SetPoint1(TPoint* _point1); //�������� ����� �����
	void SetPoint2(TPoint* _point2); //�������� ������ �����

	double GetX1(); //�������� ���������� X ������ �����
	double GetY1(); //�������� ���������� Y ������ �����
	double GetX2(); //�������� ���������� X ������� �����
	double GetY2(); //�������� ���������� Y ������� �����
	TPoint* GetPoint1(); //�������� ��������� �� ����� ����� �������
	TPoint* GetPoint2(); //�������� ��������� �� ������ ����� �������

	void Show(); //����� ����� �� �������
};
