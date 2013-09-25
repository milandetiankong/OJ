class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = S.size();
        int m = T.size();
        vector< vector<int> > dp(m+1, vector<int>(n+1, 1));
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = 0;
            for (int j = 1; j <= n; ++j) {
                if (S[j-1] == T[i-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        } 
        return dp[m][n];
    }
};
