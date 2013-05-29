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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *root = 0;
        ListNode **proot = &root;
        int n = lists.size();
        int finished = 0;
        ListNode **pmax;
        int min;
        while (1) {
            finished = 1;
            min = ~(1<<31);
            for (int i=0; i<n; ++i) {
                if (lists[i]) {
                    finished = 0;
                    if (lists[i]->val < min) {
                        min = lists[i]->val;
                        pmax = &lists[i];
                    }
                }
            }
            if (finished) break;
            *proot = *pmax;
            *pmax = (*pmax)->next;
            proot = &((*proot)->next);
        }
        *proot = 0;
        return root;
    }
};


