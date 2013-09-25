class Solution {
    vector<vector<bool> > dp;
    string ss;
    vector<vector<string> > ret;
    vector<string> item;
    int n;
    void dfs(int x) {
        if (x >= n) {
            ret.push_back(item);
            return ;
        }
        for (int i = 1; i+x <= n; ++i) {
            if (dp[x][x+i-1]) {
                item.push_back(ss.substr(x, i));
                dfs(x+i);
                item.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        n = s.size();
        dp.assign(n,  vector<bool>(n, 1));
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j + i < n; ++j) {
                if (s[j] == s[j+i]) dp[j][j+i] = dp[j+1][j+i-1];
                else dp[j][j+i] = 0;
            }
        }
        ss = s;
        item.clear();
        ret.clear();
        dfs(0);
        return ret;
    }
};
