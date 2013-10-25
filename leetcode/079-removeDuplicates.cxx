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

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int index = 0;
        char flag = 0;
        if (n == 0) return 0;
        
        for (int i = 1; i < n; ++i) {
            if (A[index] != A[i]) {
                A[++index] = A[i];
                flag = 0;
            } else if (flag == 0) {
                A[++index] = A[i];
                flag = 1;
            }
        }
        return index + 1;
    }
};
