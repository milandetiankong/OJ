class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string dp(s.size()+1, 0);
        dp[0] = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (dp[i]) {
                for (auto &x : dict) {
                    if (s.substr(i, x.size()) == x) dp[i+x.size()] = 1;
                }
            }
            if (dp[s.size()]) return true;
        }
        return false;
    }
};
