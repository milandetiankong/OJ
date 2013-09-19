class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        char map[1002][1002];   //g++ initialized to 0
        int a=0, b=0;
        for (int i=1; i<n; ++i) {
            for (int j=0; j+i<n; ++j) {
                if (s[j] == s[j+i]) map[j][j+i] = map[j+1][j+i-1];
                else map[j][j+i] = 1;
                if (map[j][j+i]==0) {
                    a = j;
                    b = j + i;
                }
            } 
        }
        return string(s.begin()+a, s.begin()+b+1);
    }
};
