class Solution {
public:
    int finditL(int A[], int n, int v) {
        if (n==1) return A[0]<v ? A[0] : v;
        n = n/2 -1;
        if (A[n] >= v) return A[n];
        if (A[n+1] <= v) return A[n+1];
        return v;
    }

    int finditR(int A[], int n, int v) {
        if (n==1) return A[0]>v ? A[0] : v;
        n = (n-1) / 2;
        if (A[n] >= v) return A[n];
        if (A[n+1] <= v) return A[n+1];
        return v;
    }

    int findMidR(int A[], int a, int B[], int b) {
        //cout << A[0] << " " << a << " " << B[0] << " " <<  b << endl;
        int mida = a/2;
        int midb = b/2;

        if (a == 0) {
            return B[midb];
        }
        if (a == 1) {
           return finditR(B, b, A[0]); 
        }

        if (A[mida] < B[midb]) {
           return findMidR(&A[mida], a-mida, B, b-mida);
        }
        if (A[mida] > B[midb]) {
            return findMidR(A, a-mida, &B[mida], b-mida); 
        }
        return A[mida];
    }

    int findMidL(int A[], int a, int B[], int b) {
        int mida = (a-1) / 2;
        int midb = (b-1) / 2;

        int mid = a / 2;
        if (a == 0) {
            return B[midb];
        }
        if (a == 1) {
            return finditL(B, b, A[0]);
        }
        if (A[mida] > B[midb]) {
            return findMidL(A, a-mid, B+mid, b-mid);
        }
        if (A[mida] < B[midb]) {
           return findMidL(A+mid, a-mid, B, b-mid);
        }
        return A[mida];
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (m<n) {
            return (findMidL(A, m, B, n) + findMidR(A, m, B, n)) / 2.0;
        } else {
            return (findMidL(B, n, A, m) + findMidR(B, n, A, m)) / 2.0;
        }
    }
};

class Solution {
    int find_kth(int A[], int m, int B[], int n, int k) {
        if ( m > n) return find_kth(B, n, A, m, k);
        // m < n
        if (m == 0) return B[k-1];
        if (k == 1) return min(A[0], B[0]);
        int pa = min(m, k/2), pb = k - pa;
        if (A[pa-1] < B[pb-1])
            return find_kth(A+pa, m-pa, B, n, k-pa);
        else if (A[pa-1] > B[pb-1])
            return find_kth(A, m, B+pb, n-pb, k-pb);
        else
            return A[pa-1];
    }
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int sum = m + n;
        if (sum & 1) {
            return find_kth(A, m, B, n, sum/2 + 1);
        } else {
            return (find_kth(A, m, B, n, sum/2) + find_kth(A, m, B, n, sum/2 + 1))/2.0;
        }
    }
};
