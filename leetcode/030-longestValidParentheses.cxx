class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        int as = 0;
        for (int i=0; i<n; ++i) {
            int tmp = 0;
            for (int j=i; j<n; ++j) {
               if (s[j] == '(') ++tmp;  else  --tmp; 
               if (tmp < 0) break;
               if (!tmp && as<(j-i+1)) as = j-i+1;
            }
        }
        return as;
    }
};
