class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const char * end = 0;
        const char * n = s;
        while (*n) ++n;
        end = n - 1;
        while (end >= s) {
            if (*end != ' ') break;
            --end;
        }
        int j = 0;
        while (end >= s) {
            if (*end == ' ') break;
            ++j;
            --end;
        }
        return j;
    }
};
