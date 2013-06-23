class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0, tmp;
        while (i < n) {
            if (A[i]<=0 || A[i]>=n) {
                ++i;
            } else {
                tmp = A[i] - 1;
                A[i] = A[tmp];
                A[tmp] = tmp + 1;
                if (A[i] == A[tmp]) ++i;
            }
        }

        for (i=0; i<n; ++i) {
            if (A[i] != i+1) {
                break;
            }
        }
        return i+1;
    }
};
