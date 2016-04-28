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

vector<int>bubble_sort(vector<int>what) {
	for (int i = 0;i < what.size();i++) {
		for (int j = what.size() - 1;j >= i;j--) {
			if (what[j] < what[i]) {
				int tmp = what[j];
				what[j] = what[i];
				what[i] = tmp;
			}
		}
	}
	return what;
}
int main(){
	srand(time(0));
	vector<int> a;
	for (int i = 0;i < 10;i++) {
		a.push_back(rand() % 20);
	}
	a = bubble_sort(a);
	return 0;
}
