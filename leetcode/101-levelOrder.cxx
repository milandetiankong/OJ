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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<TreeNode *> q;
        TreeNode *tmp;
        vector<vector<int> > ret;
        vector<int> item;
        if (! root) return ret;
        q.push(root);
        q.push(0);
        while (! q.empty()) {
            tmp = q.front();
            q.pop();
            if (tmp) {
                item.push_back(tmp->val);
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            } else {
                ret.push_back(item);
                item.clear();
                if (q.empty()) break;
                q.push(0);
            }
        }
        return ret;
    }
};
