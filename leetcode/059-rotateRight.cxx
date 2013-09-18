/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * ret, *tmp, *p = head;
        if (head == 0 || k == 0) return head;
        int len = 0;
        while (p) {
            ++len;
            p = p->next;
        }
        k %= len;
        k = len - k;
        p = head;
        while (--k) {
            p = p->next;
        }
        if (p->next == 0) return head;
        ret = p->next;
        p->next = 0;
        p = ret;
        while (p->next) {
            p = p->next;
        }
        p->next = head;
        return ret;
    }
};
