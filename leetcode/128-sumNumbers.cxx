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
    int dfs(TreeNode *root, int i) {
        i *= 10;
        i += root->val;
        if (root->left==0 && root->right==0) return i;
        
        int left = 0, right = 0;
        if (root->left) left = dfs(root->left, i);
        if (root->right) right = dfs(root->right, i);
        return left + right;
    }
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function 
        if (! root) return 0;
        return dfs(root, 0);
    }
};
