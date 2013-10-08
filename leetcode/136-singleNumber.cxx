class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int mod = 1, ret = 0, ct;
        for (int i = 0; i < sizeof(A[0])*8; ++i) {
            ct = 0;
            for (int j = 0; j < n; ++j) {
                if (A[j] & mod) ++ct;
            }
            if (ct % 3) ret |= mod;
            mod <<= 1;
        }
        return ret;
    }
};
