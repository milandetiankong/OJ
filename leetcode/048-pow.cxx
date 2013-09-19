class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return 1;
        long long  int step = n;
        if (step < 0) step = -step;
        double ret = 1;
        double tmp = x;
        while(step) {
            if (step%2) {
                ret *= tmp;
            }
            tmp *= tmp;
            step >>= 1;
        }
        if (n < 0) return 1.0/ret;
        return ret;
    }
};
