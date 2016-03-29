#include "stdafx.h"
#include "rectangle.h"
#include<iostream>
#include<cmath>

using namespace std;

rectangle::rectangle(int x, int y, int sq, int per) :shape(x, y, sq, per)
{
	cout << "Rectangle was made" << endl;
}

rectangle rectangle::operator+(const rectangle &other)
{
	int d = pow(this->per / 2, 2);//находим стороны прямоугольников с помощью квадратного уравнения
	int des = d - 4 * 1 * this->sq;//дескриминант
	int a1 = (-(this->per/2) + sqrt(des)) / 2;
	int b1 = (-(this->per/2) - sqrt(des)) / 2;

	d = pow(other.per / 2, 2);
	des = d - 4 * 1 * other.sq;
	int a2 = (-(other.per/2) + sqrt(des)) / 2;
	int b2 = (-(other.per/2) + sqrt(des)) / 2;
	return rectangle(this->x, this->y,(a1+a2)*(b1+b2), 2*(a1+a2+b1+b2));
}

void rectangle::show_info()
{
	cout << "Rectangle: " <<" x->" << x << " " << "y->" << y << " " << "sq->" << sq << " " << "per->" << per << endl;
}


rectangle::~rectangle()
{
	cout << "Rectangle was broken" << endl;
}
