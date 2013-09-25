class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        vector<vector<bool> > m(n,  vector<bool>(n, 1));
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j + i < n; ++j) {
                if (s[j] == s[j+i]) m[j][j+i] = m[j+1][j+i-1];
                else m[j][j+i] = 0;
            }
        }
        vector<int> dp(n+1, 1);
        dp[0] = 0;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i-1] + 1;
            for (int j = 1; j <= i; ++j) {
                if (m[j-1][i-1]) dp[i] = min(dp[i], dp[j-1]+1);
            }
        }
        return dp[n]-1;
    }
};
