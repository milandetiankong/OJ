#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;
class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int mod = 1, ret = 0, ct;
        for (int i = 0; i < sizeof(A[0])*8; ++i) {
            ct = 0;
            for (int j = 0; j < n; ++j) {
                if (A[j] & mod) ++ct;
            }
            if (ct % 3) ret |= mod;
            mod <<= 1;
        }
        return ret;
    }
};

int main(void) {
    int A[] = {1, 2, 3, -4, 3, 2, 1, 3, 2, 1};
    Solution sl;
    cout << sl.singleNumber(A, 10) << endl;
    return 0;
}
