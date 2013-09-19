class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        char m[256];
        for (int i=0; i<9; ++i) {
           for (int j='1'; j<='9'; ++j) m[j] = 0;
           for (int j=0; j<9; ++j) {
               if (board[i][j] == '.') continue;
               if (m[board[i][j]]) return false;
               else m[board[i][j]] = 1;
           }
           for (int j='1'; j<='9'; ++j) m[j] = 0;
           for (int j=0; j<9; ++j) {
               if (board[j][i] == '.') continue;
               if (m[board[j][i]]) return false;
               else m[board[j][i]] = 1;
           }
        }
        for (int x=0; x<9; x+=3) {
            for (int y=0; y<9; y+=3) {
                for (int j='1'; j<='9'; ++j) m[j] = 0;
                for (int i=x; i<x+3; ++i) {
                    for (int j=y; j<y+3; ++j) {
                        if (board[i][j] == '.') continue;
                        if (m[board[i][j]]) return false;
                        else m[board[i][j]] = 1;
                    }
                }
            }
        }
        return true;
    }
};
