#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	n++;
	m++;
	k++;
	int p[n][m][k];
	vector<int>res;
	vector<int>a(n);
	vector<int>b(m);
	vector<int>c(k);
	int y=0;
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<m;i++){
		cin>>b[i];
	}
	for(int i=1;i<k;i++){
		cin>>c[i];
	}
	a[0]=-1;
	b[0]=-2;
	c[0]=-3;


	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			for(int t=1;t<k;t++){
				if(a[i]==b[j]&&b[j]==c[t]){				
					p[i][j][t]=p[i-1][j-1][t-1]+1;
				}else{
					p[i][j][t] = max({p[i-1][j][t],p[i][j-1][t],p[i][j][t-1]});
				}
			}
		}
	}
	
	cout<<p[n-1][m-1][k-1]<<endl;

   	int i,j,t;
   	i=n-1;
   	j=m-1;
   	t=k-1;
   	while (i>0&&j>0&&t>0) {
		if (a[i] == b[j]&&b[j]==c[t]) {
		    res.push_back(a[i]);
		    i--;
		    j--;
		    t--;
       		}
		else {
		    if (p[i-1][j][t] >= p[i][j-1][t]&&p[i-1][j][t]>=p[i][j][t-1])
			i--;
		    else if(p[i][j-1][t] >= p[i-1][j][t]&&p[i][j-1][t]>=p[i][j][t-1])
			j--;
		    else{
			t--;
		    }
		}
   	 }
    	reverse(res.begin(),res.end());
    	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}

	cout<<endl;
	return 0;
}

