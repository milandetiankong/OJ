class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size(), tmp;
        if (! n) return 0;

        vector<int> dp(n, 0);
        dp[0] = (s[0] != '0');
        if (n == 1) return dp[0];

        if (s[1] != '0') dp[1] = dp[0];
        tmp = (s[0]-'0')*10 + s[1] - '0';
        if (tmp <= 26 && s[0] != '0') dp[1] += 1;

        for (int i = 2; i < n; ++i) {
            if (s[i] == '0') dp[i] = 0;
            else dp[i] = dp[i-1];
            tmp = (s[i-1]-'0')*10 + s[i] - '0';
            if (tmp <= 26 && s[i-1] != '0') tmp = dp[i-2];
            else tmp = 0;
            dp[i] += tmp;
        }
        return dp[n-1];
    }
};
