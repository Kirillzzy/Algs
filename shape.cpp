#include "stdafx.h"
#include "shape.h"
#include<iostream>

using namespace std;

shape::shape(int x, int y, int sq, int per) :x(x), y(y), sq(sq), per(per)
{
	count++;
}


shape::~shape()
{
	cout << "BYE" << endl;
}
