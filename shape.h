#pragma once

using namespace std;

class shape
{
public:
	shape(int x=0,int y=0,int sq=0,int per=0);
	virtual void show_info() = 0;
	virtual ~shape();
	static int count;

protected:
	int x, y, sq, per;
};

