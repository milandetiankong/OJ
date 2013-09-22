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
    int last;
    char flag;
    bool dfs(TreeNode *root) {
        if (! root) return true;

        if (root->left && !dfs(root->left)) return false;

        if (flag && root->val <= last) return false;
        else flag = 1;
        last = root->val;

        if (root->right && !dfs(root->right)) return false;
        return true;
    }
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        flag = 0;
        return dfs(root);
    }
};
