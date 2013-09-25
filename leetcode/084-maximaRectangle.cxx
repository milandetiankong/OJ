//http://discuss.leetcode.com/questions/260/maximal-rectangle
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
//http://discuss.leetcode.com/questions/260/maximal-rectangle
        int n = matrix.size();
        if (! n) return 0;
        int m = matrix[0].size();
        vector<int> H(m), L(m), R(m, m);
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            int left = 0, right = 0;
            for (int j = 0; j <m; ++j) {
                if (matrix[i][j] == '1') {
                    ++H[j];
                    L[j] = max(L[j], left); //nearest left zero position
                } else {
                    left = j+1;
                    H[j] = L[j] = 0;
                    R[j] = n;
                }
            }
            for (int j = m-1; j>=0; --j) {
                if (matrix[i][j] == '1') {
                    R[j] = min(R[j], right); // nearest left zero postion
                    ret = max(ret, H[j]*(R[j]-L[j]));
                } else {
                    right = j;
                }
            }
        }
        return ret;
    }
};
