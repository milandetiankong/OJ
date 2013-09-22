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
    vector<int> s;
    TreeNode *build(int i, int j) {
        if (i > j) return 0;
        if (i == j) return new TreeNode(s[i]);
        int mid = (i + j)/2;
        TreeNode * ret = new TreeNode(s[mid]);
        ret->left = build(i, mid-1);
        ret->right = build(mid+1, j);
        return ret;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        s = num; 
        return build(0, num.size()-1);
    }
};
