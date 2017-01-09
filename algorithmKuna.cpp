//
//  main.cpp
//  tryCpp2
//
//  Created by Kirill Averyanov on 05/01/2017.
//  Copyright © 2017 Kirill Averyanov. All rights reserved.
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
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

vector<vector<int>>g;
vector<int>match;
vector<bool>used;

bool dfs(int v){
    if(used[v]){
        return false;
    }
    used[v] = true;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if(match[to] == -1 || dfs(match[to])){
            match[to] = v;
            return true;
        }
    }
    return false;
}



int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n);
    for(int i = 0; i < n; i++){
        while(true){
            int a;
            cin >> a;
            if(a == 0){
                break;
            }
            a--;
            g[i].push_back(a);
        }
    }
    
    match.assign(m, -1);
    for(int v = 0; v < n; v++){
        used.assign(n, false);
        dfs(v);
    }
    vector<pair<int, int>>ans;
    for(int i = 0; i < m; i++){
        if(match[i] != -1){
            ans.push_back(make_pair(match[i] + 1, i + 1));
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}



