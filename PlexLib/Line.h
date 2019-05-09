#pragma once
#include "../PlexLib/Point.h"

class TLine
{
protected:
	TPoint* point1; //указатель на левй конец
	TPoint* point2; //указатель на правый конец
	bool del_flag_1; //флаг, разрешающий удаление левой точки
	bool del_flag_2; //флаг, разрешающий удаление правой точки
public:
	TLine();
	TLine(const TPoint* _point1, const TPoint* _point2); //конструктор инициализатор от двух точек
	TLine(const double x1, const double y1, const double x2, const double y2); //конструктор иницилизатор от координат двух точек
	TLine(const TLine& line); //конструктор копирования
	virtual ~TLine(); //деструктор

	void SetX1(const double _x1); //изменить координату X левого конца
	void SetY1(const double _y1); //изменить координату Y левого конца
	void SetX2(const double _x2); //изменить координату X правого конца
	void SetY2(const double _y2); //изменить координату Y правого конца
	void SetPoint1(TPoint* _point1); //изменить левый конец
	void SetPoint2(TPoint* _point2); //изменить правый конец

	double GetX1(); //получить координату X левого конца
	double GetY1(); //получить координату Y левого конца
	double GetX2(); //получить координату X правого конца
	double GetY2(); //получить координату Y правого конца
	TPoint* GetPoint1(); //получить указатель на левый конец отрезка
	TPoint* GetPoint2(); //получить указатель на правый конец отрезка

	void Show(); //вывод линии на консоль
};
