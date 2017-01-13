//
//  main.cpp
//  tryCpp3
//
//  Created by Kirill Averyanov on 06/01/2017.
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

ll sqr(ll a){
    return a * a;
}

struct Node{
    ll key, priority, count, num;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(){}
    Node(ll key): key(key), priority(rand()), count(1), num(sqr(key)), left(nullptr), right(nullptr){}
    
    void myRelax(ll key){
        this -> key = key;
        this -> num = sqr(key);
    }
};

void relax(Node *node){
    if(!node){
        return;
    }
    node -> count = 1;
    node -> num = sqr(node -> key);
    if(node -> left){
        node -> count += node -> left -> count;
        node -> num += node -> left -> num;
    }
    if(node -> right){
        node -> count += node -> right -> count;
        node -> num += node -> right -> num;
    }
}

Node* kth(Node *node, ll x, ll ind){
    ll tmp;
    if(!node){
        return nullptr;
    }
    if(!(node -> left)){
        tmp = 1;
    }else{
        tmp = node -> left -> count + 1;
    }
    ind += tmp;
    if(ind == x){
        return node;
    }
    if(!(node -> left)){
        return kth(node -> right, x, ind);
    }
    if(!(node -> right)){
        return kth(node -> left, x, ind - tmp);
    }
    if(ind > x){
        return kth(node -> left, x, ind - tmp);
    }
    return kth(node -> right, x, ind);
}

pair<Node*, Node*>split(Node* node, ll x){
    if(!node){
        return make_pair(nullptr, nullptr);
    }
    if(node -> key <= x){
        pair<Node*, Node*>tmp = split(node -> right, x);
        node -> right = tmp.first;
        relax(node);
        return make_pair(node, tmp.second);
    }else{
        pair<Node*, Node*>tmp = split(node -> left, x);
        node -> left = tmp.second;
        relax(node);
        return make_pair(tmp.first, node);
    }
}


Node* merge(Node* first, Node* second){
    if(!first){
        return second;
    }else if(!second){
        return first;
    }
    if(first -> priority < second -> priority){
        first -> right = merge(first -> right, second);
        relax(first);
        return first;
    }else{
        second -> left = merge(first, second -> left);
        relax(second);
        return second;
    }
}

Node* find(Node* node, ll x){
    if(!node){
        return node;
    }
    if(node -> key == x){
        return node;
    }
    if(node -> key < x){
        return find(node -> right, x);
    }else{
        return find(node -> left, x);
    }
}


Node* insert(Node *first, Node *second){
    if(find(first, second -> key)){
        return first;
    }
    pair<Node*, Node*>tmp = split(first, second -> key);
    Node* t = merge(tmp.first, second);
    return merge(t, tmp.second);
}

Node* pop(Node* node, ll x){
    pair<Node*, Node*>tmp1 = split(node, x);
    pair<Node*, Node*>tmp2 = split(tmp1.first, x - 1);
    return merge(tmp2.first, tmp1.second);
}



Node* next(Node* &node, ll x){
    pair<Node*, Node*>tmp = split(node, x);
    Node* ans = tmp.second;
    while(ans && ans -> left){
        ans = ans -> left;
    }
    merge(tmp.first, tmp.second);
    return ans;
}

Node* prev(Node* &node, ll x){
    pair<Node*, Node*>tmp = split(node, x - 1);
    Node* ans = tmp.first;
    while(ans && ans -> right){
        ans = ans -> right;
    }
    merge(tmp.first, tmp.second);
    return ans;
}

ll getSize(Node* node){
    if(!node){
        return 0;
    }
    return node -> count;
}


pair<Node*, Node*>mySplit(Node* node, ll x){
    if(!node){
        return make_pair(nullptr, nullptr);
    }
    if(getSize(node -> left) < x){
        pair<Node*, Node*>tmp = mySplit(node -> right, x - getSize(node -> left) - 1);
        node -> right = tmp.first;
        relax(node);
        return make_pair(node, tmp.second);
    }else{
        pair<Node*, Node*>tmp = mySplit(node -> left, x);
        node -> left = tmp.second;
        relax(node);
        return make_pair(tmp.first, node);
    }
}

pair<ll, ll>myDel(ll a){
    if(a % 2 == 0){
        return make_pair(a / 2, a / 2);
    }else{
        return make_pair(a / 2, a / 2 + 1);
    }
}

void print(Node* node){
    if(!node){
        return;
    }
    print(node -> left);
    cout << node -> key << " ";
    print(node -> right);
}

void printNums(Node* node){
    if(!node){
        return;
    }
    print(node -> left);
    cout << node -> num << " ";
    print(node -> right);
}


Node* makeDo(Node* node, ll l, ll r){
    pair<Node*, Node*>tmp = mySplit(node, l - 1);
    pair<Node*, Node*>tmp2 = mySplit(tmp.second, r - l + 1);
    Node* p = merge(tmp2.first, tmp.first);
    p = merge( p, tmp2.second);
    return p;
}

ll getMin(Node* &node, ll l, ll r){
    pair<Node*, Node*>tmp = mySplit(node, l - 1);
    pair<Node*, Node*>tmp2 = mySplit(tmp.second, r - l + 1);
    ll ans = 0;
    if(tmp2.first){
        ans = tmp2.first -> num;
    }

    Node* p = merge(tmp2.first, tmp2.second);
    merge(tmp.first, p);
    return ans;
}

Node* addMy(Node* node, ll l, Node* x){
    pair<Node*, Node*>tmp = mySplit(node, l);
    Node* p = tmp.first;
    p = merge(p, x);
    return merge(p, tmp.second);
}


Node* e1(Node* node, ll v){
    pair<Node*, Node*>tmp = mySplit(node, v);
    pair<Node*, Node*>tmp1 = mySplit(tmp.first, v - 1);
    Node* pp = tmp1.second;
    pair<ll, ll>de = myDel(pp -> key);
    pair<Node*, Node*>tmp2 = mySplit(tmp1.first, v - 2);
    Node* leb = tmp2.second;
    pair<Node*, Node*>tmp3 = mySplit(tmp.second, 1);
    Node* rib = tmp3.first;
    if(!leb){
        rib -> key += pp -> key;
        relax(rib);
    }else if(!rib){
        leb -> key += pp -> key;
        relax(leb);
    }else{
        leb -> key += de.first;
        rib -> key += de.second;
        relax(leb);
        relax(rib);
    }
    Node* p = merge(tmp2.first, leb);
    relax(tmp2.first);
    p = merge(p, rib);
    relax(p);
    p = merge(p, tmp3.second);
    relax(p);
    return p;
}

Node* e2(Node* node, ll v){
    pair<Node*, Node*>tmp = mySplit(node, v);
    pair<Node*, Node*>tmp1 = mySplit(tmp.first, v - 1);
    Node* pp = tmp1.second;
    pair<ll, ll>de = myDel(pp -> key);
    Node* q1 = new Node(de.first);
    Node* q2 = new Node(de.second);
    Node* p = merge(tmp1.first, q1);
    p = merge(p, q2);
    p = merge(p, tmp.second);
    return p;
}

ll getSum(Node* node, ll l){
    pair<Node*, Node*>tmp = mySplit(node, l);
    ll ans = 0;
    if(tmp.second){
        ans = tmp.second -> count;
    }
    merge(tmp.first, tmp.second);
    return ans;
}



int main(){
    int n, l;
    cin >> n >> l;
    Node* head = nullptr;
    vector<pair<int, int>>w(n);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        w[i].second = i;
        w[i].first = (a * l + i);
    }
    sort(w.begin(), w.end());
    ll ans = 0;
    for(int i = 0; i < n; i++){
        head = addMy(head, w[i].second, new Node(1));
        ans += getSum(head, w[i].second);
    }
    cout << ans << endl;
    return 0;
}


