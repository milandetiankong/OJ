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
    int height(TreeNode *root) {
        if (! root) return 0;
        int left = height(root->left);
        if (left < 0) return -1;
        int right = height(root->right);
        if (right < 0) return -1;
        if (abs(left-right) > 1) return -1;
        return max(left+1, right+1);
    }
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return height(root) < 0 ? false : true;
    }
};
