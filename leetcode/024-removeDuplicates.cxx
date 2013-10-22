class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i=0, j=1;
        if (n == 0) return 0;
        while (j<n) {
            if (A[j] != A[i]) {
                A[++i] = A[j];
            }
            ++j;
        }
        return i+1;
    }
};
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int index = 0;
        if (n == 0) return 0;
        for (int i = 0; i < n; ++i) {
            if (A[index] != A[i]) A[++index] = A[i];
        }
        return index + 1;
    }
};
