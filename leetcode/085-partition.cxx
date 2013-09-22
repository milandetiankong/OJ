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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode r1(0), r2(0);
        ListNode * p1 = &r1, *p2 = &r2;
        while (head) {
            if (head->val < x) {
                p1->next = head;
                p1 = head;
            } else {
                p2->next = head;
                p2 = head;
            }
            head = head->next;
        }
        p1->next = r2.next;
        p2->next = 0;
        return r1.next;
    }
};
