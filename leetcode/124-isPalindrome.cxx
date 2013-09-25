class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        int i = 0, j = n-1;
        while (i < j) {
            if (! isalnum(s[i])) {
                ++i;
                continue;
            }
            if (! isalnum(s[j])) {
                --j;
                continue;
            }
            if (toupper(s[i]) != toupper(s[j])) return false;
            ++i;
            --j;
        }
        return true;
    }
};
