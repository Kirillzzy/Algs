#include <bits/stdc++.h>                                      
              
using namespace std;

//merge sort
int nums;
int a[100000000];
int t[100000000];


void merge(int a[], int l, int r){
	int m = (l + r) / 2;
	int n = m;
	int p = l;
	int p1 = l;
	while(l < n && m < r){
		if(a[l] < a[m]){
			t[p] = a[l];
			l++;
		}else{
			t[p] = a[m];
			m++;
		}
		p++;
	}
	while(l < n){
		t[p] = a[l];
		l++;
		p++;
	}
	while(m < r){
		t[p] = a[m];
		m++;
		p++;
	}
	for(int i = p1; i < r; i++){
		a[i] = t[i];
	}
}

void merge_sort(int a[], int first, int last){
	if(last - first == 1){
		return;
	}
	merge_sort(a, first, (first + last) / 2);
	merge_sort(a, (first + last) / 2, last);
	merge(a, first, last);
	for(int i = 0; i < nums; i++){
		cout << a[i] << " " ;
	}
	cout << endl;
}



int main()
{
	cin >> nums;
	for(int i = 0; i < nums; i++){
		cin >> a[i];
	}
 	merge_sort(a, 0, nums);
	return 0;
}   
