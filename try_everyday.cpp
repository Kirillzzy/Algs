// try_everyday.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<new>
#include<map>
#include<time.h>
#include<math.h>

using namespace std;


int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main(){

	return 0;
}