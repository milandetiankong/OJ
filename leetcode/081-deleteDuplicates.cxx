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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (! head) return head;
        ListNode *ret = head, * end = ret;
        head = head->next;
        while (head) {
            if (head->val != end->val) {
                end->next = head;
                end = head;
            }
            head = head->next;
        }
        end->next = 0; 
        return ret;
    }
};
