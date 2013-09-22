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
    TreeNode * min;
    TreeNode * max;
    TreeNode * last;
    void dfs(TreeNode *root) {
        if (! root) return;
        if (root->left) dfs(root->left);

        if (last) {
            if (root->val <= last->val) {
                if (! min) {
                    min = last;
                    max = root;
                }
                else max = root;
            }
        }
        last = root;

        if (root->right) dfs(root->right);
    }
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        min = max = last = 0;
        dfs(root);
        swap(min->val, max->val);
    }
};
