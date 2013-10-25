/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
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
