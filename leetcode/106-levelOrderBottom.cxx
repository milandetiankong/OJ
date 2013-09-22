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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        vector<int> item;
        if (! root) return ret;
        queue<TreeNode *> q1, q2;
        TreeNode * tmp;
        q1.push(root);
        while (! q1.empty()) {
            tmp = q1.front();
            q.pop();
            item.push_back(tmp->val);
            if (tmp->left) q2.push(tmp->left);
            if (tmp->right) q2.push(tmp->right);
            if (q1.empty()) {
                ret.insert(ret.begin(), item);
                item.clear();
                q1.swap(q2);
            }
        }
        return ret;
    }
};
