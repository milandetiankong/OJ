class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n < 1) return 0;
        int ret = A[0];
        for (int i = 1; i < n; ++i) {
            ret ^= A[i];
        }
        return ret;
    }
};
