#include "stdafx.h"
#include "circle.h"
#include<iostream>


using namespace std;


circle::circle(int x,int y,int sq,int per):shape(x,y,sq,per)
{
	cout << "Circle was made" << endl;
}

circle circle::operator+(const circle & other)
{
	const int n = 4;//штука которую прибавляем к диаметру первой окружности
	const int pi = 3;
	int rad = sqrt(this->sq / pi) * 2 + n;
	return circle(this->x, this->y, 2 * pi*rad, pi*pow(rad, 2));
}

void circle::show_info()
{
	cout << "Circle: " << " x->" << x << " " << "y->" << y << " " << "sq->" << sq << " " << "per->" << per << endl;
}


circle::~circle()
{
	cout << "Circle was broken" << endl;
}
