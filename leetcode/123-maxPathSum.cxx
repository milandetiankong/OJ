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
    int ret;
    int postOrder(TreeNode * root) {
        int left = 0, right = 0;
        if (root->left) left = postOrder(root->left);
        if (root->right) right = postOrder(root->right);
        ret = max(ret, root->val + left + right);
        int tmp =  root->val + max(left, right);
        if (tmp < 0) tmp = 0;
        return tmp;
    }
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function 
        ret = - (1 << 30);
        if (! root) return 0;
        postOrder(root);
        return ret;
    }
};
