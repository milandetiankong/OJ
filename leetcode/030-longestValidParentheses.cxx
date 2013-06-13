class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        int as = 0;
        for (int i=1; i<n; ++i) {
            int tmp = 0;
            for (int j=i; j>=0; --j) {
               if (s[j] == '(') --tmp;  else  ++tmp; 
               if (tmp < 0) break;
               if (!tmp && as<(i-j+1)) as = i-j+1;
            }
        }
        return as;
    }
};
