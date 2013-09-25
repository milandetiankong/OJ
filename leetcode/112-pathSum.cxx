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
    int t;
    vector<vector<int> > ret;
    vector<int> item;
public:
    void dfs(TreeNode *root, int cur) {
        int tmp = cur + root->val; 
        item.push_back(root->val);
        if (tmp == t && root->left==0 && root->right==0) {
            ret.push_back(item);
        }
        if (root->left) dfs(root->left, tmp);
        if (root->right) dfs(root->right, tmp);
        item.pop_back();
    }
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        item.clear();
        if (! root) return ret;
        t = sum;
        dfs(root, 0);
        return ret;
    }
};
