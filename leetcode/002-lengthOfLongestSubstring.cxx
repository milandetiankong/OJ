class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<bool> used(256, 0);
        int ret = 0;
        int ct  = 0;
        int pos = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (used[s[i]]) {
                while (s[pos] != s[i]) {
                    used[s[pos]] = 0;
                    --ct;
                    ++pos;
                }
                --ct;
                ++pos;
            }
            used[s[i]] = 1;
            ++ct;
            if (ret < ct) ret = ct;
        }
        return ret;
    }
};
