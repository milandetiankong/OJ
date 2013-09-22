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
    int t;
public:
    bool dfs(TreeNode *root, int cur) {
        int tmp = cur + root->val; 
        // maybe negative, if tmp > t, not return false;
        if (tmp == t && root->left==0 && root->right==0) return true; 
        if (root->left && dfs(root->left, tmp)) return true;
        if (root->right && dfs(root->right, tmp)) return true;
        return false;
    }
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function        
        if (! root) return 0;
        t = sum;
        return dfs(root, 0);
    }
};
