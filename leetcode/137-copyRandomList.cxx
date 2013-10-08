/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
typedef RandomListNode Node;

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        unordered_map<Node *, Node *> copy;
        if (! head) return head;
        Node * root = new Node(head->label);
        copy[head] = root;
        Node * pre = root, * p = head->next;
        while (p) {
            pre->next = new Node(p->label);
            copy[p] = pre->next;
            p = p->next;
            pre = pre->next;
        }
        copy[0] = 0;
        p = head;
        pre = root;
        while (p) {
            pre->random = copy[p->random];
            p = p->next;
            pre = pre->next;
        }
        return root;
    }
};
