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
    bool dfs(TreeNode *p, TreeNode *q) {
        if (p && !q) return false;
        if (!p && q) return false;
        if (!p && !q) return true;
        if (p->val != q->val) return false;
        if(!dfs(p->left, q->left))  return false;
        if(!dfs(p->right, q->right)) return false;
        return true;
    }
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return dfs(p, q);
    }
};
