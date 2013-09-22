class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int k, tmp;
        for (int i = 0; i < n; ++i) {
            tmp = B[i];
            k = m + i;
            while (k && A[k-1] > tmp) {
                A[k] = A[k-1];
                --k;
            }
            A[k] = tmp;
        } 
    }
};
