class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s1.size();
        if (s2.size() != n) return false;
        vector<vector<vector<char> > > dp(n,\
                vector<vector<char> >(n, vector<char>(n, 0)));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j][0] = (s1[i] == s2[j]);
            }
        }
        for (int k = 1; k < n; ++k) {
            for (int i = 0; i+k < n; ++i) {
                for (int j = 0; j+k < n; ++j) {
                    dp[i][j][k] = 0;
                    for (int l = 1; l <= k; ++l) {
                        if (dp[i][j][l-1] && dp[i+l][j+l][k-l] ||
                                dp[i][j+k-l+1][l-1] && dp[i+l][j][k-l]) {
                            dp[i][j][k] = 1;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][n-1];
    }
};
