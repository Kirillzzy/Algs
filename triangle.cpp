#include "stdafx.h"
#include "triangle.h"
#include<iostream>

using namespace std;

triangle::triangle(int x,int y,int sq,int per):shape(x,y,sq,per)
{
	cout << "Triangle was made" << endl;
}

triangle triangle::operator+(const triangle & other)
{
	
	return triangle(this->x, this->y, this->sq * 2 + other.sq * 2, this->per + other.per);//здесь с площадью и периметром я не парился специально
}

void triangle::show_info()
{
	cout << "Triangle: " << " x->" << x << " " << "y->" << y << " " << "sq->" << sq << " " << "per->" << per << endl;
}


triangle::~triangle()
{
	cout << "Triangle was broken" << endl;
}
