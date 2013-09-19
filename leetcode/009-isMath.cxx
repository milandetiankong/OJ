class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       if (*s == 0 && *p == 0) return 1;
       
       if (p[1] != '*') {
           if (*s == 0 || *p==0) return 0;
           if (*p == '.') return isMatch(s+1, p+1);
           if (*p == *s) return isMatch(s+1, p+1);
           return 0;
       }
       
       if (isMatch(s, p+2)) return 1;
       do{
           if (*p == *s || *p == '.') {
               ++s;
           } else {
               break;
           }
           if (isMatch(s, p+2)) return 1;
       } while (*s);
       return 0;
    }
};
