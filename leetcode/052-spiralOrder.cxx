class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int x = 0, y = 0;
        int a = matrix.size();
        int b = a ? matrix[0].size() : 0;
        vector<int> ret;
        while (a && b) {
            for (int i = y; i < y+b; ++i) {
                ret.push_back(matrix[x][i]);
            }
            if (a == 1) break;
            for (int i = x+1; i < x+a; ++i) {
                ret.push_back(matrix[i][y+b-1]);
            }
            
            if ( b==1 ) break;
            for (int i = y+b-2; i >= y; --i) {
                ret.push_back(matrix[x+a-1][i]);
            }
            
            for (int i = x+a-2; i > x; --i) {
                ret.push_back(matrix[i][y]);
            }
            ++x;
            ++y;
            if (a > 2) a -= 2; else a = 0;
            if (b > 2) b -= 2; else b = 0;
        }
        return ret;
    }
};
