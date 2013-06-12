class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        char buf[n/2 +1][n];
        for (int i=0; i<n; ++i) {
            buf[0][i] = 1;
        }
        int as = 0;
        for (int i=1; i<=n/2; ++i) {
            for (int j=i*2; j<=n; ++j) {
                int x = j - i*2;
                if (s[x]=='(' && s[j-1]==')') {
                    if (buf[i-1][j-1]) {
                        buf[i][j] = 1;
                        as = i*2;
                        continue;
                    }
                }
                int k;
                for (k=1; k<i; ++k) {
                    if (buf[k][x+k*2] && buf[i-k][j]) {
                        break;
                    }
                }
                if (k == i) {
                    buf[i][j] = 0;
                } else {
                    buf[i][j] = 1;
                    as = i*2;
                }
            }
        }
        
        return as;
    }
};
