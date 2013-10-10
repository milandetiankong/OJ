class Solution {
public:
    double pow(double x, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        long long t = n;
        if (n < 0) t = -t;
        double ret = 1.0;
        while (t) {
            if(t & 1) ret *= x;
            x *= x;
            t >>= 1;
        }
        if (n < 0) return 1.0/ret;
        return ret;
    }
};
