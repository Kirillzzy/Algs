#include <bits/stdc++.h>

using namespace std;

#define ll long long



int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int d[n + 1];
	int p[n + 1];
	for(int i = 0; i < n; i++){
		d[i] = 1;
		p[i]  = -1;
		for(int j = 0; j < i; j++){
			if(a[j] < a[i]){
				if(1 + d[j] > d[i]){
					d[i] = 1 + d[j];
					p[i] = j;
				}
			}
		}
	}
	int ans = 0;
	int pos = 0;
	for(int i = 0; i < n; i++){
		if(d[i] > ans){
			ans = d[i];
			pos = i;
		}
	}
	cout << ans << endl;
	vector<int>path;
	while(pos != -1){
		path.push_back(a[pos]);
		pos = p[pos];
	}
	for(int i = path.size() - 1; i >= 0; i--){
		cout << path[i] << " ";
	}
	cout << endl;
	return 0;
}
