#include <bits/stdc++.h>

using namespace std;

#define ll long long


class Knapsack{
public:
	Knapsack(){};
	vector<ll>ans;
	ll n, m;
	ll a[10005][100005];
	ll wts[1005];
	ll ps[1005];

	void findAns(int k, int s){
		if(a[k][s] == 0){
			return;
		}
		if(a[k - 1][s] == a[k][s]){
			findAns(k - 1, s);
		}
		else{
			findAns(k - 1, s - wts[k]);
			ans.push_back(k);
		}
	}

	void main(){
		cin >> n >> m;
		n++;
		m++;
		memset(a, 0, sizeof(a));
		for(int i = 1; i < n; i++){
			cin >> wts[i];
		}
		for(int i = 1; i < n; i++){
			cin >> ps[i];
		}

		wts[0] = 0;
		ps[0] = 0;

		for(int i = 1; i < n; i++){
			for(int j = 1; j < m; j++){
				if(j >= wts[i]){
					a[i][j] = max(a[i - 1][j], a[i - 1][j - wts[i]] + ps[i]);
				}else{
					a[i][j] = a[i - 1][j];
				}
			}
		}

		findAns(n - 1, m - 1);
		cout << ans.size() << endl;
		for(int i = 0; i < ans.size(); i++){
			cout << ans[i] << " ";
		}
		cout << endl;
	}

};




int main(){
	Knapsack *knp = new Knapsack();
	knp -> main();
	return 0;
}

