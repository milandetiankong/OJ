class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i=-1, j=0;
        while (j < n) {
            if (A[j] != elem) {
                A[++i] = A[j];
            }
            ++j;
        }
        return i+1;
    }
};
