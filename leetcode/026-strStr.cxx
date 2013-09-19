class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        char *p = haystack;
        char *x, *y;
        if (*needle==0) return p;
        while (*p) {
            x = p;
            y = needle;
            while (*x && *y && *x==*y) {
                ++x;
                ++y;
            }
            if (*y==0) return p;
            if (*x==0) return 0;
            ++p;
        }
        return 0;
    }
};
