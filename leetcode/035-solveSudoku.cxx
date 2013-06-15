class Solution {
public:
    bool solve(vector<vector<char> > &bd, int k) {
        if (k == 81) return true;
        int x, y;
        x = k/9; y = k%9;
        while (bd[x][y] != '.') {
            ++k;
            if (k == 81) return true;
            x = k/9;
            y = k%9;
        }
        for (int i='1'; i<='9'; ++i) {
            int tmp = 0;
            for (int j=0; j<9; ++j) {
                if (bd[x][j] == i) ++tmp;
                if (bd[j][y] == i) ++tmp;
            }
            if (tmp) continue;

            int a, b;
            a = x / 3 * 3;
            b = y / 3 * 3;
            for (int j=a; j<a+3; ++j) {
                for (int k=b; k<b+3; ++k) {
                    if (bd[j][k] == i) ++tmp;
                }
            }
            if(tmp) continue;
            bd[x][y] = i;
            if (solve(bd, k+1)) return true;
            bd[x][y] = '.';
        }
        return false;
    }
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function 
        solve(board, 0);                        
    }
};
