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
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (head == 0) return 0;
        int len = 1;
        ListNode * p = head;
        while (p->next) {
            ++len;
            p = p->next;
        }
        k = k % len;
        if (k == 0) return head;

        p->next = head;
        k = len - k;

        len = 0;
        p = head;
        while (p) {
            ++len;
            if (len == k) break;
            p = p->next;
        }
        head = p->next;
        p->next = 0;
        return head;
    }
};

