#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	int n, m;

	cin >> n;
	int a[++n];

	for(int i = 1; i < n; i++){
		cin >> a[i];
	}

	cin >> m;
	int b[++m];

	for(int i = 1; i < m; i++){
		cin >> b[i];
	}

	int dp[n][m];
	memset(dp, 0, sizeof(dp));
	
	a[0] = -1;
	b[0] = -2;

	for(int i = 1; i < n; i++){
		for(int j = 1; j < m; j++){
			if(a[i] == b[j]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[n - 1][m - 1] << endl;

	vector<int>ans;
	int i = n - 1;
	int j = m - 1;
	while(i > 0 && j > 0){
		if(a[i] == b[j]){
			ans.push_back(a[i]);
			i--;
			j--;
		}
		else if(dp[i - 1][j] >= dp[i][j - 1]){
			i--;
		}else{
			j--;
		}

	}
	reverse(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}

