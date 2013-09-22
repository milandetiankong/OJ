class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function        
        vector<int> dp(n+1, 1);
        int tmp;
        for (int i = 2; i <= n; ++i) {
            tmp = 0;
            for (int j = 1; j <= i; ++j) {
                tmp += dp[j-1]*dp[i-j];
            }
            dp[i] = tmp;
        }
        return dp[n];
    }
};
