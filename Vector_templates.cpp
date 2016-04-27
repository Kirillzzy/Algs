// try_everyday.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<new>
#include<map>
#include<math.h>

using namespace std;

template<class T>
class list {
	int n;
	int size;
	T *mass;
	void realocate() {
		int siz = size * 2;
		T *new_mass = new T[siz];
		for (int i = 0;i < size;i++)
			new_mass[i] = mass[i];
		delete[]mass;
		size = siz;
		mass = new_mass;
	}
public:
	list(int n = 0) :n(n) {
		mass = new T[1];
		size = 1;
	}
	~list() { delete[] mass; }
	int operator [](int a) {
		return mass[a];
	}
	int get_size() {
		return n;
	}
	void push(T a) {
		if (n == size) {
			realocate();
		}
		mass[n++] = a;
	}
};


int main() {
	list<int> a;
	a.push(10);
	a.push(15);
	a.push(1);
	cout << a.get_size() << a[2]<<endl;
	return 0;
}
