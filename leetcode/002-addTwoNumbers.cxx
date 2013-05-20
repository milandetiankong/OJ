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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *root = new ListNode(0);
        ListNode *p = root;
        int carry = 0;
        while (l1 || l2) {
            if (l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(carry % 10);
            carry /= 10;
            p = p->next;
        }
        if (carry) {
           root->val = carry; 
           p->next = root;
           p =  root->next;
           root->next = 0;
           return p;
        }
        p = root->next;
        delete root;
        return p; 
    }
};
