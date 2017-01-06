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

const ll MAXN = 300000;

struct rng{
    int num = -1;
    bool isLeft = true;
    bool isRight = true;
};

vector<rng>t(4 * MAXN);

int n;
bool flag = true;
int lvl = 1;

void unit(int v){
    if(t[v * 2].isRight || t[v * 2].isLeft){
        t[v].isLeft = true;
    }else{
        t[v].isLeft = false;
    }
    
    if(t[v * 2 + 1].isLeft || t[v * 2 + 1].isRight){
        t[v].isRight = true;
    }else{
        t[v].isRight = false;
    }
}

void build(int v, int tl, int tr){
    if(tl == tr){
        t[v].isRight = true;
        t[v].isLeft = true;
        t[v].num = lvl++;
    }else{
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        unit(v);
    }
}

void get(int v, int tl, int tr, int val){
    if(tl == tr){
        t[v].isRight = false;
        t[v].isLeft = false;
        cout << t[v].num << endl;
        return;
    }
    int tm = (tl + tr) / 2;
    if(flag && t[v].isLeft && val <= tm){
        get(v * 2, tl, tm, val);
    }
    if(flag && t[v].isRight){
        get(v * 2 + 1, tm + 1, tr, val);
    }
    unit(v);
}


void update(int v, int tl, int tr, int val){
    if(tl == tr){
        t[v].isLeft = true;
        t[v].isRight = true;
        return;
    }
    int tm = (tl + tr) / 2;
    if(val <= tm){
        update(v * 2, tl, tm, val);
    }else{
        update(v * 2 + 1, tm + 1, tr, max(val, tm + 1));
    }
    unit(v);
}



int main(){
    int k;
    cin >> k;
    build(1, 0, MAXN);
    for(int i = 0; i < k; i++){
        int a;
        cin >> a;
        if(a < 0){
            update(1, 0, MAXN, abs(a) - 1);
        }else{
            get(1, 0, MAXN, a - 1);
            flag = true;
        }
    }
    return 0;
}

