#include <limits.h>
#include <stdio.h>
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

//#include "*.cxx"

#define PRINT(x) printf(#x ": %x\n", x)
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int gap = INT_MAX;
        int sum, tmp;
        int n = num.size();

        if (n < 3) return 0;
        sort(num.begin(), num.end());
        
        for (int i=0; i<n-2; ++i) {
            sum = target - num[i];
            cout << "sum:" << sum << endl;
            int l = i+1, r = n-1;
            while(l < r) {
                tmp = num[l] + num[r];
                cout << "tmp:" << tmp << endl;
                gap = min(gap, abs(sum-tmp));
                cout << "gap:" << gap<< endl;
                if (tmp < sum) ++l;
                else if (tmp > sum) --r;
                else break;
            }
        }
        return gap;
    }
};

int main(void) {
    vector<int> num = {0, 0 , 0 };
    Solution sl;
    cout << sl.threeSumClosest(num, 1) << endl;
    return 0;
}
