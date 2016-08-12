#include <bits/stdc++.h>                                      
              
using namespace std;


//knapsack
int knapsack(vector<int>& wts, int W)
{
	size_t n = wts.size();
	vector<bool> dp(W + 1);
	dp[0] = 1;
	for(int i=0;i<n;i++){
		for(int j=W;j>=wts[i];j--){
			dp[j] = max(dp[j],dp[j-wts[i]]);
		}
	}

	for(int i=W;i>=0;i--){
		if(dp[i]==1){
			return i;
		}
	}
}

int main(){
	int s,n;
	cin>>s>>n;
	vector<int>wts(n);
	for(int i=0;i<n;i++){
		cin>>wts[i];
	}
	cout<<knapsack(wts,s)<<endl;
	return 0;
}