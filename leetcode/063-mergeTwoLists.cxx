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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode root(0), *last = &root;
        while (l1 || l2) {
            if (l1 && l2) {
                if (l1->val < l2->val) {
                    last->next = l1;
                    l1 = l1->next;
                } else {
                    last->next = l2;
                    l2 = l2->next;
                }
            } else if (l1) {
                    last->next = l1;
                    l1 = l1->next;
            } else {
                    last->next = l2;
                    l2 = l2->next;
            }
            last = last->next;
        }
        last->next = 0;
        return root.next;
    }
};
