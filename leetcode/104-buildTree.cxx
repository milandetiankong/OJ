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
    vector<int> pre, in;
    TreeNode *build(int a, int b, int x, int y) {
        if (a > b) return 0;
        int val = pre[a];
        int k = x;
        while (val != in[k]) ++k;
        TreeNode *ret = new TreeNode(val);
        ret->left = build(a+1, a+k-x, x, k-1);
        ret->right = build(a+k-x+1, b, k+1, y);
        return ret;
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function 
        in = inorder;
        pre = preorder;
        return build(0, pre.size()-1, 0, in.size()-1);
    }
};
