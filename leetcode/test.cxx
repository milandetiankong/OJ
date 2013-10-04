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
        if (n < 1) return 0;
        int ret = A[0];
        for (int i = 1; i < n; ++i) {
            ret ^= A[i];
        }
        return ret;
    }
};
int main(void) {
    int A[] = {1, 2, 3, 4, 3, 2, 1};
    Solution sl;
    cout << sl.singleNumber(A, 7) << endl;
    return 0;
}
