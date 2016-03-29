#pragma once
#include"shape.h"

using namespace std;


class rectangle:public shape
{
public:
	rectangle(int x, int y, int sq, int per);
	rectangle operator +(const rectangle & other);
	void show_info();
	~rectangle();
};

