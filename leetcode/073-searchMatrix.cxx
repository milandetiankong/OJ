class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        if (! m) return false;
        int n = matrix[0].size();
        if( ! n) return false;
        int x = 0, y = n-1;
        while (x<m && y>=0) {
            if (target == matrix[x][y]) {
                return true;
            } else if (target < matrix[x][y]) {
                --y;
            } else {
                ++x;
            }
        }
        return false; 
    }
};
