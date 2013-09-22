class Solution {
    int m, n;
    string w;
    vector<vector<char> > used;
    bool dfs(vector<vector<char> > &board, int x, int y, int step) {
        if (w[step] != board[x][y]) return false;
        used[x][y] = 1;
        ++step;
        if (step == w.size()) return true;

        if (x && ! used[x-1][y]) {
            if(dfs(board, x-1, y, step)) return true;
        }
        if (y && ! used[x][y-1]) {
            if (dfs(board, x, y-1, step)) return true;
        }
        if (x < m-1 && ! used[x+1][y]) {
            if (dfs(board, x+1, y, step)) return true;
        }
        if (y < n-1 && ! used[x][y+1]) {
            if (dfs(board, x, y+1, step)) return true;
        }
        used[x][y] = 0;
        return false;
    }
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        w = word;
        m = board.size();
        if (! m) return false;
        n = board[0].size();
        if (! n) return false; 
        used.assign(m, vector<char>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(dfs(board, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
