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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function 
        if (! root) return 0;
        stack<TreeNode *> q1, q2;
        TreeNode *tmp;
        q1.push(root);
        int ct = 1;
        while (! q1.empty()) {
            tmp = q1.top();
            q1.pop();
            if (tmp->left) q2.push(tmp->left);
            if (tmp->right) q2.push(tmp->right);
            if (! (tmp->left || tmp->right)) return ct;
            if (q1.empty()) {
                ++ct;
                q1.swap(q2);
            }
        }
        return ct;
    }
};
