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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode **pp = &head;
        if(! head) return head;
        ListNode *q = head->next;
        ListNode *tmp;
        while (q) {
            tmp = *pp;
            *pp = q;
            tmp->next = q->next;
            q->next = tmp;
            pp = &(tmp->next);
            if (! *pp) break;
            q = (*pp)->next;
        }
        return head;
    }
};
