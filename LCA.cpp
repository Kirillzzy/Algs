//
//  main.cpp
//  tryCpp
//
//  Created by Kirill Averyanov on 23/12/2016.
//  Copyright © 2016 Kirill Averyanov. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <functional>
#include <numeric>
#include <random>
#include <cassert>

using namespace std;

typedef long long ll;

const int N = 200000;
const int K = 30;

ll pr, tim, level, last;

vector<vector<ll>>g(N);
vector<pair<ll, ll>>levels;
vector<ll>a(10000001 * 2);
vector<ll>tin(N);
vector<ll>tout(N);
pair<ll, ll> M[N][K];
vector<bool>used(N);


ll funclog(ll x, ll y){
    ll k = log2(y - x + 1);
    return min(M[x][k], M[y - (1 << k) + 1][k]).second;
}


ll LCA(ll u, ll v){
    if (tin[u] > tin[v]) {
        swap(u, v);
    }
    if (tout[u] > tout[v]) {
        return u;
    }
    return funclog(tin[u], tout[v] - 1);
}

// dfs
void dfs(ll v){
    used[v] = true;
    levels.push_back(make_pair(level, v));
    tim++;
    tin[v] = tim;
    for(int i = 0; i < g[v].size(); i++){
        level++;
        dfs(g[v][i]);
        level--;
        levels.push_back(make_pair(level, v));
    }
    tim++;
    tout[v] = tim;
}



int main(){
    // init
    ll n, m, x, y, z;
    cin >> n >> m;
    for(int i = 1; i < n; ++i){
        cin >> pr;
        g[pr].push_back(i);
    }
    
    tim = -1;
    dfs(0);
    cin >> a[0] >> a[1] >> x >> y >> z;
    x = x % n;
    y = y % n;
    z = z % n;
    for (int i = 2; i < 2 * m; i++){
        a[i] = (x * a[i - 2] + y * a[i - 1] + z) % n;
    }
    
    for (int i = 0; i < levels.size(); i++){
        M[i][0] = levels[i];
    }
    
    for (int i = 1; (1 << i <= levels.size()); i++){
        for (int j = 0; j + (1 << i) < levels.size(); j++){
            M[j][i] = min(M[j][i - 1], M[j + (1 << (i - 1))][i - 1]);
        }
    }
    ll ans = 0;
    for (int i = 0; i < m; i++){
        last = LCA((a[2 * i] + last) % n, a[2 * i + 1]);
        ans += last;
    }
    cout << ans << endl;
    return 0;
}
