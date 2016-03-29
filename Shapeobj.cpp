#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<Windows.h>
#include<ctime>
#include"rectangle.h"
#include"triangle.h"
#include"circle.h"


using namespace std;

int shape::count = 0;

int main()
{
	cout << "Main in" << endl;
	rectangle a1(0, 0, 12, 14);
	rectangle a2(1, 1, 12, 14);
	a1.show_info();
	a2.show_info();
	rectangle a3 = a1 + a2;
	a3.show_info();
	cout << "Now you have " << shape::count << " objects" << endl;
	
	circle b1(0, 0, 6, 5);
	circle b2(1, 1, 6, 5);
	b1.show_info();
	b2.show_info();
	circle b3 = b1 + b2;
	b3.show_info();
	cout << "Now you have " << shape::count << " objects" << endl;

	triangle c1(0, 0, 6, 5);
	triangle c2(1, 1, 6, 5);
	c1.show_info();
	c2.show_info();
	triangle c3 = c1 + c2;
	c3.show_info();
	cout << "Now you have " << shape::count << " objects" << endl;

    return 0;
}

