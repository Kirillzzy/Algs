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



struct Rule
{
	string left;
	string right;
	bool final;
	void print() {
		cout << left << "->" << (final ? "." : "") << right;
	}
	bool is_applicable(string s) {
		//if(find(s,left)!=-1)
		if (s.find(left) != -1)
			return true;
		else
			return false;
	}
	int find(string wh, string what) {
		int length = what.size();
		int ok;
		for (int i = 0;i<wh.size();i++) {
			if (wh[i] != what[0])
				continue;
			string ka;
			for (int j = i;j<length + i;j++) {
				ka += wh[j];
			}
			if (ka == what) {
				return i;
			}
		}
		return -1;
	}
	string apply(string s) {
		//int a=find(s,left);
		int a = s.find(left);
		if (a != -1) {
			s.replace(a, left.size(), right);
		}
		return s;
	}
};
struct MarkovAlgorithm
{
	vector<Rule>rules;
	void print() {
		for (auto it : rules) {
			it.print();
			cout << endl;
		}
	}
	string apply(string s) {
		for (int i = 0;i<rules.size();i++) {
			bool ma = false;
			bool k = rules[i].is_applicable(s);
			if (k) {
				ma = true;
			}
			else
				continue;
			if (ma) {
				if (i == rules.size() - 1)
					ma = true;
			}
			s = rules[i].apply(s);
			if (ma)
				i = -1;
		}
		return s;
		return "out";
	}
};
#if 0
cout << "HI" << endl;
#endif

int main()
{
	/*MarkovAlgorithm x;
	Rule r;
	r.left="10";
	r.right="01";
	x.rules.push_back(r);
	x.print();
	string s;
	cin>>s;
	s=x.apply(s);
	cout<<s<<endl;*/
	string s = "hihihi";
	int a = s.find("i");
	return 0;
}

