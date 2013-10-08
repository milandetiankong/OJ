/* Given an array A of integers, find the maximum of j-i subjected to
 * the constraint of A[i] < A[j];
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int maxDistance(int A[], int n) {
    vector<int> dec(A, A+n);
    vector<int> inc(A, A+n);

    for (int i = 1; i < n; ++i) {
        dec[i] = min(dec[i], dec[i-1]);
    }
    for (int i = n-2; i >= 0; --i) {
        inc[i] = max(inc[i], inc[i+1]);
    }
    int j = 0, k = 1;
    int ret = 0;
    while (j < n && k < n-1) {
        while (k<n-1 && inc[k+1]>A[j]) ++k;
        cout << "FIND:" << j << "->" << k << endl;
        ret = max(k-j, ret);
        while (++j<n && dec[j] == dec[j-1]) /*dummy*/;
    }
    return ret;
}



int main(void) {
    int A[] = {4, 3, 5, 2, 1, 3, 2, 3};
    cout << maxDistance(A, 8) << endl;
    return 0;
}
