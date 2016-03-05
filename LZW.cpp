
#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	unordered_map<string, int>m;
	for (int i = 0;i < 256;i++) {
		char c = (char)i;
		string v;
		v += c;
		m[v] = i;
	}
	string t;
	int v = 256;
	vector<int>vec;
	for (int i = 0;i <= s.size();i++) {
		t += s[i];
		if (m.count(t) > 0)
			continue;
		m[t] = v;
		v++;
		t.pop_back();
		vec.push_back(m[t]);
		t.clear();
		t += s[i];
	}
	v = 256;
	vector<string>ab;
	for (int i = 0;i < 256;i++){
		char c = (char)i;
		string s;
		s += c;
		ab.push_back(s);
	}
	int l;

	for (int i = 0;i < vec.size()-1;i++) {
		int b = vec[i];
		int ser = vec[i + 1];
		string b1 = (string)ab[vec[i]];
		string b2;
		char b3;
		if (ser > ab.size()-1)
			b2 = b1;
		else
			b2 += (char)ab[ser][0];
		cout << ab[b];
		string gag;
		gag += b1 + b2;
		ab.push_back(gag);
		l = i;
	}
	cout << ab[vec[l + 1]];
	return 0;

}

