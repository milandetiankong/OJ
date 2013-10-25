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


int main(void) {
    vector<int> num = {0, 0 , 0 };
    Solution sl;
    cout << sl.threeSumClosest(num, 1) << endl;
    return 0;
}
