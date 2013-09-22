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
        ListNode *ret = 0, *end,*last= head;
        int ct = 0;
        head = head->next;
        while (head) {
            if( last->val == head->val) {
                ++ct;
                delete head;
            } else {
                if (ct) {
                    delete last;
                } else if (ret) {
                    end->next = last;
                    end = last;
                } else {
                    ret = last;
                    end = last;
                }
                last = head;
                ct = 0;
            }
            head = head->next;
        }
        last->next = 0;
        if (ct) {
            delete last;
            last = 0;
        }
        if (ret) end->next = last;
        else ret = last;
        return ret;
    }
};
