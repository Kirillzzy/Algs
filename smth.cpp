#include <bits/stdc++.h>

using namespace std;

#define ll long long

int p[500][500];


int main(){
	int n,m;
	cin>>n>>m;
	//
	vector<int>a(n);
	vector<int>b(m);
	int y=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
	}


	for(int i=0;i<n;i++){
		if(a[i]==b[0]){
			y=1;
		}
		p[i][0] = y;
	}
	y=0;

	for(int i=0;i<m;i++){
		if(b[i]==a[0]){
			y=1;
		}
		p[0][i] = y;
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(a[i]==b[j]){				
				p[i][j]=p[i-1][j-1]+1;
			}else{
				int u = max(p[i-1][j],p[i][j-1]);
				p[i][j]=u;
			}
		}
	}
	cout<<p[n-1][m-1]<<endl;
    vector<int>s;

    int i = 0;

   	int j = 0;

    while (i < n && j < m)

    {

	if (a[i]==b[j])

	{

	    s.push_back(a[i]);

	    i++; j++;

	}

	else if (p[i+1][j] >= p[i][j+1]) i++;

	else j++;

    }

    for(int i=0;i<s.size();i++){
    	cout<<s[i]<<" ";
    }
	cout<<endl;
	return 0;
}