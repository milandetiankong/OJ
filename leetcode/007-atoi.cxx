class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0, flag=1;
        long long as = 0;
        long long max = 1LL<<32;
        
        while (str[i] == ' ') ++i;
        
        if (str[i] == '+') {
            ++i;
        } else if (str[i] == '-') {
            flag = -1;
            ++i;
        }
        
        while (str[i]>='0' && str[i]<='9') {
            as *= 10;
            as += str[i] - '0';
            if (as > max) {
                break;
            }
            ++i;
        }
        as *= flag;
        int right = ~(1<<31);
        int left  = 1<<31;
        if (as < left) as = left;
        if (as > right) as = right;
        return as;
    }
};
