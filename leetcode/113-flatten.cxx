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
    TreeNode * last;
    void dfs(TreeNode * root) {
        if (last) last->right = root;
        last = root;
        TreeNode * right = root->right;

        if (root->left) dfs(root->left);
        root->left = 0;
        if (right) dfs(right);
    }
public:
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (! root) return root;
        last = 0;
        dfs(root);
        return root;
    }
};
