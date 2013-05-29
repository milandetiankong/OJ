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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *rhead = 0, *tmp;
        if (k<=1 || !head) return head;
        ListNode **pp = &rhead, **st;
        ListNode *end = head;
        ListNode *s;
        while (end) {
            *pp = end;
            end = end->next;
            st = pp;
            pp = & ((*pp)->next);
            s = end;
            int step = k-1;
            while (end && step) {
                end = end->next;
                --step;
            }
            if (step) break;
            while (s != end) {
                tmp = s;
                s = s->next;
                tmp->next = *st;
                *st = tmp;
            }
        }
        while (s) {
            *pp = s;
            pp = &(s->next);
            s = s->next;
        }
        *pp = 0;
        return rhead;
    }
};

