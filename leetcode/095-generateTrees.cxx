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
    vector<TreeNode *> dfs(int a, int b) {
        vector<TreeNode *> ret;
        vector<TreeNode *> left;
        vector<TreeNode *> right;
        TreeNode * tmp;
        if (a > b) {
            ret.push_back(0);
            return ret;
        }
        if (a == b) {
            ret.push_back(new TreeNode(a));
            return ret;
        }
        for (int k = a; k <= b; ++k) {
            left = dfs(a, k-1);
            right = dfs(k+1, b);
            for (int i = 0; i < left.size(); ++i) {
                for (int j = 0; j < right.size(); ++j) {
                    tmp =  new TreeNode(k);
                    tmp->left = left[i];
                    tmp->right = right[j];
                    ret.push_back(tmp);
                }
            }
        }
        return ret;
    }
public:
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return dfs(1, n);
        
    }
};
