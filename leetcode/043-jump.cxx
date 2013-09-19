class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> dp(n, 0);
        vector<int> min(n, 0);
        
        for (int i = n-2; i >= 0; --i) {
            if (A[i] == 0) {
                dp[i] = 1<<30;
                min[i] = dp[i];
                continue;
            }
            int end = i + A[i] > n-1 ? n-1 : i + A[i];
            dp[i] = min[end] + 1;
            min[i] = dp[i];
            for (int j = i+1; j < n; ++j) {
                if (min[j] > min[i]) {
                    min[j] = min[i];
                } else break;
            }
        }
        return dp[0];
    }
};
