#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;


class Solution {
    string x;
    char error(int a, int b) {
        cout << "ab:" << a << " "  << b << endl;
        int sum = 0;
        for (int i = a; i <= b; ++i) {
            sum *= 10;
            sum += (x[i]-'0');
        }
        cout << "return:" <<  sum << endl;
        if (sum <= 255) return 0;
        else return 1;
    }
public:
    vector<string> abc(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        x = s;
        int n = s.size();
        vector<string> ret;
        for (int i = 0; i < n-1; ++i) {
            cout << "i:" << i << endl;
            if (i >= 3) break;
            if (error(0, i)) continue;
            for (int j = i+1; j < n-1; ++j) {
                cout << "j" << j << endl;
                if (j-i > 3) break;
                if (error(i+1, j)) continue;
                for (int k = j+1; k < n-1; ++k) {
                    cout << "k" << k << endl;
                    cout << "#" << i  << " " << j << " " << k << endl;
                    if (k-j > 3) break;
                    if (error(j+1, k)) continue;
                    if (error(k+1, n-1)) continue;
                    cout << "ANS:" << endl;
                    string tmp(string(s.begin(), s.begin()+i+1) + "."
                            + string(s.begin()+i+1, s.begin()+j+1) + "."
                            + string(s.begin()+j+1, s.begin()+k+1) + "."
                            + string(s.begin()+k+1, s.end()));
                    cout << i << j << k << endl;
                    cout << tmp << endl;
                    ret.push_back(string(s.begin(), s.begin()+i+1) + "."
                            + string(s.begin()+i+1, s.begin()+j+1) + "."
                            + string(s.begin()+j+1, s.begin()+k+1) + "."
                            + string(s.begin()+k+1, s.end()));
                }
            }
        }
        return ret;
    }
};
int main(void) {
    Solution sl;
    int x[] = {1, 1, 1, 3, 1};
    vector<int> in(1, 1);
    //string minWindow(string S, string T) {
    sl.abc("0000");
    return 0;
}
