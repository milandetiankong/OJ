class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        if (! m) return;
        int n = matrix[0].size();
        if (! n) return;

        vector<int> fm(m, 0), fn(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    fm[i] = 1;
                    fn[j] = 1;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            if (fm[i]) {
                for (int j = 0; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (fn[i]) {
                for (int j = 0; j < m; ++j) {
                    matrix[j][i] = 0;
                }
            }
        }
    }
};
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        if (! m) return;
        int n = matrix[0].size();
        if (! n) return;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            if (matrix[i][0]==0) {
                for (int j = 1; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (matrix[0][i]==0) {
                for (int j = 1; j < m; ++j) {
                    matrix[j][i] = 0;
                }
            }
        }
    }
};
