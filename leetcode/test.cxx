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

  struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        typedef RandomListNode Node;
        Node * next, *p = head;
        if (! head) return head;
        while (p) {
            next = p->next;
            p->next = new Node(p->label);
            p->next->next = next;
            p= next;
        }
        p = head;
        while (p) {
            if(p->random) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
        p = head;
        Node *ret = p->next;
        next = ret;
        p = next->next;
        while (p) {
            head->next = p;
            next->next = p->next;
            head = p;
            next = p->next;
            p = next->next;
        }
        head->next = 0;
        next->next = 0;
        return ret;
    }
};
int main(void) {
    int len = sizeof(int);
    PRINT(len);
    int x = 0x80000001;
    cout << x << endl;

    PRINT(1 << 31);
    PRINT(0x80000001 << 1);
    PRINT(x << 1);

    PRINT(0x80000001 >> 1);
    PRINT(x =  x >> 1);
    PRINT(x =  x >> 1);
    PRINT(x =  x >> 1);

    x = -1;
    cout << (x << 1) << endl;


/*
    Solution sl;
    string s = "leetacode";
    unordered_set<string> dict= {"leet", "code", "a"};
    cout << sl.x(s, dict) << endl;
    */

    return 0;
}
