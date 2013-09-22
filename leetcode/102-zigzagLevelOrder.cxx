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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<TreeNode *> s1, s2;
        TreeNode * tmp;
        vector<vector<int> > ret;
        vector<int> item;
        if (! root) return ret;
        s1.push(root);
        char flag = 1;
        while (! s1.empty()) {
            tmp = s1.top();
            s1.pop();
            item.push_back(tmp->val);
            if (flag) {
                if (tmp->left) s2.push(tmp->left);
                if (tmp->right) s2.push(tmp->right);
            } else {
                if (tmp->right) s2.push(tmp->right);
                if (tmp->left) s2.push(tmp->left);
            }
            if (s1.empty()) {
                ret.push_back(item);
                item.clear();
                s1.swap(s2);
                flag = ! flag;
            }
        }
        return ret;
    }
};
