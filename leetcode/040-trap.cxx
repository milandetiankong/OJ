class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max = 0, sum = 0, last;
        for (int i=0; i<n; ++i) {
            sum += A[i];
            if (max < A[i]) max = A[i];
        }
        sum = n * max - sum;
        
        last = 0;
        for (int i=0; i<n; ++i) { 
            if (A[i] > last) {
                sum -= (A[i]-last) * i;
                last = A[i];
            }
            if (A[i] == max) break;
        }

        last = 0;
        for (int i=n-1; i>=0; --i) {
            if (A[i] > last) {
                sum -= (A[i]-last) * (n-1-i);
                last = A[i];
            }
            if (A[i] == max) break;
        }
        return sum;
    }
};
