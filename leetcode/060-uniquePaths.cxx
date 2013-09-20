class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long ret = 1;
        int all = m + n - 2;
        m = m < n ? m-1 : n-1;
        if (m == 0) return 1;
        for (int i = 0; i < m; ++i) {
            ret *= all;
            --all;
        }
        for (int i = 2; i <= m; ++i) {
            ret /= i;
        }
        return ret;
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (m == 0 || n == 0) return 0;
        if (m == 1) return 1;
        vector<int> dp(m, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                dp[j] += dp[j-1];
            }
        }
        return dp[m-1];
    }
};
