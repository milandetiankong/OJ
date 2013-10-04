//#! g++ test.cxx -std=c++0x
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution1 {
public:
    void x(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.        
        int n = num.size();
        int  j = n-1;
        while (--j >= 0) {
            if (num[j] < num[j+1]) break;
        }
        if (j < 0) {
            reverse(num.begin(), num.end());
            return ;
        }
        int i = n;
        while (--i > j) {
            if (num[i] > num[j]) break;
        }
        swap(num[i], num[j]);
        reverse(num.begin()+j+1, num.end());
    }
};
class Solution2 {
public:
    void x(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n =  num.size();
        if (n < 2) return;
        
        int max = num[n-1];
        int x = n-2;
        
        for (; x>=0; --x) {
            if (num[x] < max) break;
            max = num[x];
        }
        if (x < 0) {
            reverse(num.begin(), num.end());
            return;
        }
        
        int min = max;
        int id = n-1;
        
        for (int i=n-1; i>x; --i) {
            if (num[i]>num[x] && num[i]<=min) {
                min = num[i];
                id = i;
            }
        }
        num[id] = num[x];
        num[x] = min;
        sort(num.begin()+x+1, num.end());
        return;
    }
};

int main(void) {
    Solution1 s1;
    Solution2 s2;
    int x[] = {7, 6, 9, 8, 5, 4};
    vector<int> v1(x, x+6);
    vector<int> v2(x, x+6);
    char ch;
    while ( cin >> ch) {
    s1.x(v1);
    s2.x(v2);
    for (int i = 0; i < v1.size(); ++i) {
        cout << v1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < v2.size(); ++i) {
        cout << v2[i] << " ";
    }
    }
    cout << endl;
    return 0;
}
