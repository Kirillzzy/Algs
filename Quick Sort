#include <bits/stdc++.h>


using namespace std;

typedef long long ll;


class foo{
public:
	foo(int n):n(n){
		items.resize(n);
	}

	foo(){
		n=10;
		items.resize(n);
	}

	void sort(){
		qsort(0,n-1);
	}

	void randomize(){
		for(int i=0;i<n;i++){
			items[i] = rand()%n;
		}
	}

	void printItems(){
		for(int i=0;i<n;i++){
			cout<<items[i]<<" ";
		}
		cout<<endl;
	}

	~foo(){}

private:
	vector<int>items;
	int n;
	void qsort(int l,int r){
		int i=l;
		int j=r;
		int x = items[(l+r)/2];
		while(i<=j){
			while(items[i]<x){
				i++;
			}
			while(items[j]>x){
				j--;
			}
			if(i<=j){
				int tmp = items[i];
				items[i]=items[j];
				items[j]=tmp;
				i++;
				j--;
			}
		}
		if(l<j){
			qsort(l,j);
		}
		if(i<r){
			qsort(i,r);
		}
	}

};


int main(){
	int n;
	cin>>n;
	foo nums(n);
	nums.randomize();
	nums.printItems();
	nums.sort();
	nums.printItems();
	return 0;
}

