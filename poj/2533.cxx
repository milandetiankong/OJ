// DP[i]表示以第i个元素结尾时，0到i区间中最长上升子序列的个数。
//
//
#include <iostream>
using namespace std;

int buf[1003];
int ct[1003];
int n;
int main(void) {
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> buf[i];
        ct[i] = 1;
    }

    int max = 1;
    for (int i=0; i<n; ++i) {
        if (max < ct[i]) max = ct[i];
        int tmp = ct[i] + 1;
        for (int j=i+1; j<n; ++j) {
            if (buf[j] > buf[i]) {
                ct[j] = ct[j]>tmp ? ct[j] : tmp;
            }
        }
    } 
    cout << max << endl;
    return 0;
}
