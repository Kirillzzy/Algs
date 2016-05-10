// ConsoleApplication14.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<string>
#include<iostream>
#include<time.h>
#include<vector>
#include<algorithm>

using namespace std;

struct sm {
	string s;
	sm(string s = "") :s(s) {}


	int find_substr(string what) {
		int slen = s.size();
		int wlen = what.size();
		int hah1 = hah(s, wlen);
		int hah2 = hah(what, wlen);
		int pow = power(11, wlen);
		for (int i = 0;i < slen - wlen+1;i++) {
			if (hah1 == hah2) {
				for (int j = 0;j < wlen;j++) {
					if (s[i + j] != what[j]) goto next;
				}
				return i;
			}
			next:
				hah1 = hah1 * 11 + (int)s[i + wlen] - s[i] * pow;
		}
		return -1;
	}

	int find_sum(string f) {
		int slen = s.length();
		int flen = f.length();
		int fhash = hashf(f, flen);
		int curhash = hashf(s, flen);
		for (int i = 0;i <= slen - flen + 1;i++) {
			if (curhash == fhash) {
				for (int j = 0;j < flen;j++) {
					if (s[i + j] != f[j]) goto next;
				}
				return i;
			}
			next: 
				curhash += (int)s[i + flen] - (int)s[i];
		}
		return -1;
	}


private:
	int hah(string s, int len) {
		int t = s[0];
		for (int i = 1;i < len;i++) {
			t = t * 11 + (int)s[i];
		}
		return t;
	}
	int hashf(string s,int len){

		int t=0;

		for(int i=0;i<len;i++){

			t+=(int)s[i];

		}

		return t;
	}

	int power(int what, int inwhat){
		int res = 1;
		for(int i=0;i<inwhat;i++)
			res*=what;
		return res;
	}
};

int main()
{
	srand(time(0));
	string s;
	for (int i = 0;i<100000;i++) {
		s += (char)(rand() % 26 + 'a');
	}
	s+="kirill";
	sm l(s);
	cout << l.find_substr("kirill") << endl;
	cout << l.find_sum("kirill") << endl;
	cout << s.find("kirill") << endl;
	return 0;
}