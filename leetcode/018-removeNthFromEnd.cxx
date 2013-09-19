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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *p=head, *p1=head;

        if (n==0) return head;
        ++n;
        while (n && p1) {
            --n;
            p1 = p1->next;
        }
        if (n==1) {
            p1 = head->next;
            delete head;
            return p1;
        }
        if (n>1) return head;

        while (p1) {
            p1 = p1->next;
            p = p->next;
        }

        p1 = p->next;
        p->next = p1->next;
        delete p1;
        return head;
    }
};
