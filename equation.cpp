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
#include <cassert>

using namespace std;

typedef long double ld;
typedef long long ll;


class yr {
public:
	yr(string s = "", float a = 0, float b = 0) : s(s), a(a), b(b){}
	~yr() {}
	virtual vector<float> ret_ans() = 0;
	virtual bool check() = 0;
	virtual vector<float> find_roots() = 0;
	virtual void chunk() = 0;

private:
	float a, b;
	string s;

};

class line_yr : public yr {
public:
	line_yr(string s = "", float a = 0, float b = 0) : s(s), a(a), b(b) {
		chunk();
	}

	~line_yr(){}

	vector<float> ret_ans() {
		return find_roots();
	}
private:
	float a, b;
	string s;

	bool check() {
		if (s == "")
			return false;
		if (s[0] == '0')
			return false;
		int u = s.find('=');
		if (u == -1)
			return false;
		return true;
	}

	void chunk() {
		assert(check() == true);
		string u;
		int last = 0;
		for (int i = last;i < s.size();i++) {
			if (s[i] == 'x') {
				last += 2;
				break;
			}
			u += s[i];
			last++;
		}
		a = stof(u);
		u = "";
		for (int i = last;i < s.size();i++)
			u += s[i];
		b = stof(u);
		u = "";
	}

	vector<float> find_roots() {
		vector<float> roots;
		roots.push_back(b / a);
		return roots;
	}
};
class kv_yr :public yr {
public:
	kv_yr(string s="", float a = 0, float b = 0, float c = 0) :s(s), a(a), b(b), c(c) {
		chunk();
		know_dec();

	}

	~kv_yr() {}

	vector<float> ret_ans() {
		return find_roots();
	}
private:
	float a, b, c, dec;
	string s;

	bool check() {
		if (s == "")
			return false;
		int u = s.find('=');
		if (s[u + 1] != '0'||u==-1)
			return false;
		return true;
	}

	void chunk() {
		assert(check() == true);
		string u;
		int last = 0;
		for (int i = last;i < s.size();i++) {
			if (s[i] == 'x') {
				last += 3;
				break;
			}
			u += s[i];
			last++;
		}
		if (u == "")
			u == "1";
		a = stof(u);
		u = "";
		for (int i = last;i < s.size();i++) {
			if (s[i] == 'x') {
				last++;
				break;
			}
			u += s[i];
			last++;
		}
		if (u == "")
			u == "1";
		b = stof(u);
		u = "";
		for (int i = last;i < s.size();i++) {
			if (s[i] == '=')
				break;
			u += s[i];

		}
		if (u == "")
			u = "0";
		c = stof(u);
		u = "";
	}

	void know_dec() {
		dec = pow(b, 2) - 4 * a*c;
	}

	vector<float> find_roots() {
		vector<float>roots;
		if (dec < 0)
			return roots;
		else if (dec == 0) {
			roots.push_back((-b) / 2 * a);
		}
		else {
			roots.push_back(((-b) + sqrt(dec)) / (2 * a));
			roots.push_back(((-b) - sqrt(dec)) / (2 * a));
		}
		return roots;
	}
};


int main()
{
	string s;
	cin >> s;
	line_yr *uravn = new line_yr(s);
	vector<float>a = uravn->ret_ans();
	for (int i = 0;i < a.size();i++)
		cout << a[i] << endl;
	return 0;
}
