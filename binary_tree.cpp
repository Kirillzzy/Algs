#include <bits/stdc++.h>


using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left, *right;
    TreeNode(int value = 0, TreeNode *left = nullptr, TreeNode *right = nullptr) : value(value), left(left), right(right){}
};

struct Tree
{
    TreeNode *root;
    int last;

    Tree() {
        root = nullptr;
        last = -1;
    }

    int Get_last() {
        return last;
    }

    int Pop_last() {
        //remove(last);
        return last;
    }


    void push(int value) {
        root = insert(root, value);
        last = value;
    }

    void deleteNodes(TreeNode *node) {
        if (!node)
            return;
        deleteNodes(node->left);
        deleteNodes(node->right);
        delete node;
    }

    ~Tree() {
        deleteNodes(root);
    }

    void print() {
        printDfs(root);
    }

private:

    TreeNode *insert(TreeNode *root, int value) {
        if (!root) {
            return new TreeNode(value);
        }
        if (root->value == value)
            return root;
        if (root->value > value) {
            root->left = insert(root->left, value);
        } else {
            root->right = insert(root->right, value);
        }
        return root;
    }

    void printDfs(TreeNode *root) {
        if (!root)
            return;
        printDfs(root->left);
        cout << root->value << " " << endl;
        printDfs(root->right);
    }
};

int main() {
    Tree *t = new Tree();
    t->push(2);
    t->push(3);
    t->push(1);
    t->print();
    delete t;
    return 0;
}
