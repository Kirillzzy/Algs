#include"stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<new>
#include<map>
#include<time.h>
#include<math.h>
#include<set>

using namespace std;

int main()
{
	int t, n, h;
	cin >> t;
	for (int u = 0;u<t;u++) {
		cin >> n >> h;
		vector<int>len(n);
		for (int i = 0;i<n;i++)
			cin >> len[i];
		vector<int>vkl(n);
		for (int i = 0;i<n;i++)
			cin >> vkl[i];
		bool on = false;
		int length = 0;
		int tmp = 0;
		int last = 0;
		for (int i = 0;i<n;i++) {
			length = 0;
			if (vkl[i] == 0) {
				for (int j = i;;j++) {
					if (j >= n)
						break;
					if (vkl[j] == 1)
						break;
					length += len[j];
					i += 1;

				}
				if (length>h)
					tmp += 1;
			}
		}



		cout << tmp << endl;


	}
	return 0;
}