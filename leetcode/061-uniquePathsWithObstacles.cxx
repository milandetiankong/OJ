class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0) return 0;

        vector<int> dp(m, 0);
        dp[0] = 1;

        for (int i = 0; i < n; ++i) {
            if (obstacleGrid[0][i]) dp[0] = 0;
            for (int j = 1; j < m; ++j) {
                if (obstacleGrid[j][i] == 0) {
                    dp[j] = 0;
                } else {
                    dp[j] += dp[j-1];
                }
            }
        }
        return dp[m-1];
    }
};
