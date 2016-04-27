// try_everyday.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<new>
#include<map>
#include<math.h>

using namespace std;


vector<bool>resheto(int n) {
	vector<bool>a(n);
	for (int i = 2;i*i <= n;i++) {
		for (int j = 2;j*i <= n;j++) {
			a[j*i] = true;
		}
	}
	return a;
}

int main() {
	int n;
	cin >> n;
	if (n < 2)
		return 0;
	vector<bool>prime = resheto(n);
	vector<int>a;
	for (int i = 2;i*i <= n;i++) {
		if (n%i == 0&&prime[i]==false) {
			a.push_back(i);
			n = n / i;
		}
	}
	if (prime.size() < n) {
		if (prime[n] == false)
			a.push_back(n);
	}
	if (a.size() <= 1) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0;i < a.size();i++)
		cout << a[i] << endl;
	return 0;
}