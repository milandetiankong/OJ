class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int x = m-1;
        int y = n-1;
        for (int i = m+n-1; i>=0; ++i) {
            if (y<0) break;
            else if (x<0) A[i] = B[y--];           
            else if (A[x] < B[y]) A[i] = B[y--];
            else A[i] = A[x--];
        }
        return ;
    }
};
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
