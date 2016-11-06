#include <bits/stdc++.h>	


using namespace std;

typedef long long ll;


const int N = 100005;

int n, m, a, b, c;
ll INF = 1e18;
int p[N];
ll d[N];
vector < pair < int, int > > g[N];

void trace(int k){
	if(p[k]!=-1) trace(p[k]); 
	cout << k + 1 << " ";
}


int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		d[i] = INF;
		p[i] = -1;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		a--;
		b--;
		g[a].push_back(make_pair(b, c));
		g[b].push_back(make_pair(a, c));
	}
	d[0] = 0;
	p[0] = -1;
	set<pair<int, int>>q;
	q.insert (make_pair (d[0], 0));
	while(!q.empty()){
			int v = q.begin() -> second;
			q.erase(q.begin());
			for(int j = 0; j < g[v].size(); j++){
				int to = g[v][j].first;
				int len = g[v][j].second;
				if(d[v] + len < d[to]){
					q.erase(make_pair(d[to], to));
					d[to] = d[v] + len;
					p[to] = v;
					q.insert(make_pair(d[to], to));
				}
			}
		}
	int ver = n - 1;
	if (d[ver] == INF) {
		cout << -1 << endl;
		return 0;
	}
	trace(ver);
	cout << endl;
	return 0;
}
