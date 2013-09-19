#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


class Solution;
int main(void) {
    Solution sl;
    int x[] = {2, 2, 0 , 1};
    return 0;
}
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int x = 0, y = 0;
        int a = matrix.size(), b = matrix[0].size();
        vector<int> ret;
        while (a || b) {
            for (int i = y; i < y+b; ++i) {
                ret.push_back(matrix[x][i]);
            }
            
            for (int i = x+1; i < x+a; ++i) {
                ret.push_back(matrix[x][y+b-1]);
            }
            
            for (int i = y+b-1; i >= y; --i) {
                ret.push_back(matrix[x+a-1][i];
            }
            
            for (int i = x+a-1; i > x; --i) {
                ret.push_back(matrix[i][y];
            }
            ++x;
            ++y;
            if (a > 2) a -= 2; else a = 0;
            if (b > 2) b -= 2; else b = 0;
        }
        return ret;
    }
};
