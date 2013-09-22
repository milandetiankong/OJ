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
public:
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<TreeNode *> s1, s2;
        TreeNode * tmp;
        int ret = 0;
        if (! root) return ret;
        s1.push(root);
        while (! s1.empty()) {
            tmp = s1.top();
            s1.pop();
            if (tmp->left) s2.push(tmp->left);
            if (tmp->right) s2.push(tmp->right);
            if (s1.empty()) {
                ++ret;
                s1.swap(s2);
            }
        }
        return ret;
    }
};
