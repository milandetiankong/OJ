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
    string addBinary(string a, string b) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int la = a.size(), lb = b.size();
        string ret(max(la, lb) + 1);
        for (int ia=la-1, ib=lb-1, i=ret.size()-1; ia>=0 || ib>=0; --i) {
            if (ia>=0) {
                ret[i] += a[ia]-'0';
                --ia;
            }
            if (ib>=0) {
                ret[i] += b[ib]-'0';
                --ib;
            }
            if (ret[i] > '1') {
                ret[i-1] = '1';
                ret[i] -= 2;
            }
        }
        if (ret[0]=='0') {
            return string(ret.begin()+1, ret.end());
        }
        return ret;
    }
};

int main(void) {
    vector<int> num = {0, 0 , 0 };
    Solution sl;
    cout << sl.threeSumClosest(num, 1) << endl;
    return 0;
}



