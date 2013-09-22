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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function        
        ListNode root(0), *end = &root, *h, *tmp;
        for (int i = 1; head; ++i) {
            if (i == m) h = end;

            if (i>m && i<=n) {
                // insert
                tmp = head->next;
                head->next = h->next;
                h->next = head;
                head = tmp;
            } else {
                end->next = head;
                end = head;
                head = head->next;
            }
        }
        end->next = 0;
        return root.next;
    }
};
