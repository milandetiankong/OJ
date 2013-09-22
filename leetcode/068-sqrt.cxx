class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x<=0) return 0;
        double ret = x;
        double tmp = x - 10;
        while (abs(ret-tmp) >= 1e-3) {
            tmp =  ret;
            ret -= (ret*ret - x)/ret/2.0;
        }
        return ret;
    }
};
