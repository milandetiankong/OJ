class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long int sum = -(1<<30), crt = 0;
        for (int i = 0; i < n; ++i) {
            crt += A[i];
            if (sum < crt) sum = crt;
            if (crt < 0) crt = 0;
        }
        return sum;
    }
};
