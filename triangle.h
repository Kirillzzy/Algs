#pragma once
#include"shape.h"

using namespace std;


class triangle:public shape
{
public:
	triangle(int x,int y,int sq,int per);
	triangle operator +(const triangle & other);
	void show_info();
	~triangle();
};

