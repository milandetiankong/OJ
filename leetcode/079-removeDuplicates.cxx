class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 0) return 0;
        int j = 1, ct = 1;
        for (int i = 1; i < n; ++i) {
            if (A[i] == A[j-1]) {
                ++ ct;
                if (ct <= 2) A[j++] = A[i];
            } else {
                A[j++] = A[i];
                ct = 1;
            }
        }
        return j;
    }
};
