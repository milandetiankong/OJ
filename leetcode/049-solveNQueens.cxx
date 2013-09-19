class Solution {
    vector< vector<string> > ret;
    vector<int> ans;
    vector<char> used;
    void dfs(int n, int k) {
        if (k == n) {
            vector<string> bd(n, string(n, '.'));
            for (int i = 0; i < n; ++i) {
                bd[ans[i]][i] = 'Q';
            }
            ret.push_back(bd);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (used[i] == 0) {
                int j;
                for (j = 0; j < k; ++j) {
                    if (k-j == abs(i-ans[j])) break;
                }
                if (j == k) {
                    used[i] = 1;
                    ans[k] = i;
                    dfs(n, k+1);
                    used[i] = 0;
                }
            }
        }
    }
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        ans.clear();
        used.clear();
        ans.resize(n);
        used.assign(n, 0);
        dfs(n, 0);
        return ret;
    }
};
