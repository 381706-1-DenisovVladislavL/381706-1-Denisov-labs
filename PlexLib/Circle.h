#pragma once
#include "../PlexLib/Point.h"

class TCircle
{
protected:
	TPoint* center;
	double radius;
public:
	TCircle(); //конструктор по умолчанию
	TCircle(const TPoint* point, double rad); //конструктор инициализатор
	TCircle(const double _x, const double _y, const double rad); //конструктор инициализатор
	TCircle(const TCircle& circle); //конструктор копирования
	virtual ~TCircle(); //деструктор

	void SetX(const double _x); //изменить координату X для центра
	void SetY(const double _y); //изменить координату Y для центра
	void SetRadius(const double rad); //изменить радиус

	double GetX(); //получить координату X для центра
	double GetY(); //получить координату Y для центра
	double GetRadius(); //получить радиус

	void Show(); //вывод круга на консоль
};