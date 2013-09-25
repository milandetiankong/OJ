class Solution {
    int n, m;
    vector<vector<char> > bd;
    void dfs(int x, int y) {
        if (bd[x][y] == 'O') {
            bd[x][y] = '#';
            dfs(x+1, y);
            dfs(x, y+1);
            dfs(x, y-1);
            dfs(x-1, y);
        }
    }
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        n = board.size();
        if (n == 0) return ;
        m = board[0].size();
        bd.clear();
        bd.push_back(vector<char>(m+2, '#'));
        vector<char> item;
        for (int i = 0; i < board.size(); ++i) {
            item = board[i];
            item.insert(item.begin(), '#');
            item.push_back('#');
            bd.push_back(item);
        }
        bd.push_back(vector<char>(m+2, '#')); 

        for (int i = 1; i <= n; ++i) {
            dfs(i, 1);
            dfs(i, m);
        }
        for (int i = 1; i <= m; ++i) {
            dfs(1, i);
            dfs(n, i);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (bd[i+1][j+1] == '#') board[i][j] = 'O';
                else if (bd[i+1][j+1] == 'O') board[i][j] = 'X';
            }
        }
    }
};
