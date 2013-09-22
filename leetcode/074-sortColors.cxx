class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int r, w, tmp;
        r = w = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] == 0) {
                tmp = A[i];
                A[i] = A[w];
                A[w] = A[r];
                A[r] = tmp;
                ++w;
                ++r;
                
            } else if (A[i] == 1) {
                tmp = A[i];
                A[i] = A[w];
                A[w] = tmp;
                ++w;
            }
        }
    }
};
