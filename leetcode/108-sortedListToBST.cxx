/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *last;
    TreeNode *build(int a, int b) {
        if (a > b) return 0;
        TreeNode * ret, * left; 
        ListNode *old;
        int mid = (a + b) / 2;
        left = build(a, mid-1);
        ret = new TreeNode(last->val);
        old = last;
        last = last->next;
        delete old;
        ret->left = left;
        ret->right = build(mid+1, b);
        return ret;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        last = head;
        int i = 0;
        while (head) {
            ++i;
            head = head->next;
        }
        return build(0, i-1);
    }
};
