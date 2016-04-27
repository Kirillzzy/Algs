// try_everyday.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
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


int binary_search(vector<int>a, int n) {
	int first = 0;
	int last = a.size() - 1;
	while (true) {
		int mid = (first + last) / 2;
		if (n == a[mid])
			return mid;
		else if (n < a[mid]) {
			last = mid - 1;
		}
		else if (n > a[mid]) {
			first = mid + 1;
		}
		if (first > last)
			return -1;
	}
}

int main(){
	srand(time(0));
	vector<int>a;
	for (int i = 0;i < 10;i++)
		a.push_back(rand() % 20);
	sort(a.begin(), a.end());
	int k = rand() % 20;
	cout << binary_search(a, k) << endl;
	return 0;
}
