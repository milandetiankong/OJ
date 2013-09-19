class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int flag = 0;
        long long a = dividend, b = divisor;
        if (a < 0 ) {
            ++flag; 
            a = -a;
        }
        if (b < 0) {
            ++flag;
            b = -b;
        }
        if (flag == 2) flag = 0;
        
        long long as = 0;
        long long ct = 1;
        long long x = a, y = b;
        while (x >= b) {
            if (x >= y) {
                x -= y;
                as += ct;
                y = y << 1;
                ct = ct << 1;
            } else {
                y = y >> 1;
                ct = ct >> 1;
            }
        }
        if (flag) return -as;
        return as;
    }
};
