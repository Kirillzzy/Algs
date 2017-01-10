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


struct Node{
    ll key, priority, count;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(){}
    Node(ll key): key(key), priority(rand()), count(1), left(nullptr), right(nullptr){}
};

void relax(Node *node){
    node -> count = 1;
    if(node -> left){
        node -> count += node -> left -> count;
    }
    if(node -> right){
        node -> count += node -> right -> count;
    }
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




int main(){
    string s;
    Node *head = nullptr;
    while(cin >> s){
        ll x;
        cin >> x;
        if(s == "insert"){
            head = insert(head, new Node(x));
        }else if(s == "exists"){
            if(find(head, x)){
                cout << "true" << endl;
            }else{
                cout << "false" << endl;
            }
        }else if(s == "delete"){
            head = pop(head, x);
        }else if(s == "next"){
            Node* ans = next(head, x);
            if(ans){
                cout << ans -> key << endl;
            }else{
                cout << "none" << endl;
            }
        }else if(s == "prev"){
            Node* ans = prev(head, x);
            if(ans){
                cout << ans -> key << endl;
            }else{
                cout << "none" << endl;
            }

        }else if(s == "kth"){
            Node* ans = kth(head, x, 0);
            if(ans){
                cout << ans -> key << endl;
            }else{
                cout << "none" << endl;
            }
        }
    }
    return 0;
}


