class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();
        if (!n) return 0;

        vector<int> dp(n, 1<<30);
        dp[0] = 0;
        for (int i = 0; i < m; ++i) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; ++j) {
                dp[j] += grid[i][j];
                if (dp[j] > dp[j-1]+grid[i][j]) {
                    dp[j] = dp[j-1] + grid[i][j];
                }
            }
        }
        return dp[n-1];
    }
};
