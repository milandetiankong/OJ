class Solution {
    int ret;
    vector<int> ans;
    vector<char> used;
    void dfs(int n, int k) {
        if (k == n) {
            ++ret;
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
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret = 0;
        ans.clear();
        used.clear();
        ans.resize(n);
        used.assign(n, 0);
        dfs(n, 0);
        return ret; 
    }
};

