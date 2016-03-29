#pragma once
#include"shape.h"

using namespace std;


class circle:public shape
{
public:
	circle(int x,int y,int sq,int per);
	circle operator+(const circle & other);
	void show_info();
	~circle();
};

