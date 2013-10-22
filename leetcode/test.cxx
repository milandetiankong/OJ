#include <limits.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

//#include "*.cxx"

#define PRINT(x) printf(#x ": %x\n", x)

struct Node {
    Node * left;
    Node * right;
    Node * parent;
};

Node *nextInorder(Node * p) {
    if (p->right) {
        Node * r = p->right;
        while (r->left) r = r->left;
        return r;
    }
    Node * f = p->parent;
    while (f) {
        if (f->left == p) return f;
        p = f;
        f = p->parent;
    }
    return 0;
}

Node *prePostorder(Node * p) {
    if (p->left) return p->left;
    if (p->right) return p->right;
    Node * f = p->parent;
    while (f) {
        if (f->right == p && f->left) return f->left;
        p = f;
        f = p->parent;
    }
}

int main(void) {
    vector<int> num = {0, 0 , 0 };
    Solution sl;
    cout << sl.threeSumClosest(num, 1) << endl;
    return 0;
}
