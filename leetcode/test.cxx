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
    int len = sizeof(int);
    PRINT(len);
    int x = 0x80000001;
    cout << x << endl;

    PRINT(1 << 31);
    PRINT(0x80000001 << 1);
    PRINT(x << 1);

    PRINT(0x80000001 >> 1);
    PRINT(x =  x >> 1);
    PRINT(x =  x >> 1);
    PRINT(x =  x >> 1);

    x = -1;
    cout << (x << 1) << endl;
    return 0;
}
