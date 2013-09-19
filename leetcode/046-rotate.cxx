class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = matrix.size() -1;
        int tmp;
        for (int i = 0; i < (n+1)/2; ++i) {
            for (int j = 0; j < n/2+1; ++j) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[n-j][i];
                matrix[n-j][i] = matrix[n-i][n-j];
                matrix[n-i][n-j] = matrix[j][n-i];
                matrix[j][n-i] = tmp;
            } 
        }
    }
};
