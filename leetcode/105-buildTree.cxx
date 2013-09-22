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
    vector<int> post, in;
    TreeNode *build(int a, int b, int x, int y) {
        if (a > b) return 0;
        int val = post[b];
        int k = x;
        while (val != in[k]) ++k;
        TreeNode *ret = new TreeNode(val);
        ret->left = build(a, a+k-x-1, x, k-1);
        ret->right = build(a+k-x, b-1, k+1, y);
        return ret;
    }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function 
        in = inorder;
        post = postorder;
        return build(0, post.size()-1, 0, in.size()-1);
    }
};
