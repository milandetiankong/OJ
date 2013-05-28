class Solution {
public:
    vector< string > as;
    void dfs(string &s, int i, int st, int n) {
        if (st==0 && n==0) {
            as.push_back(s);
            return;
        }
        if (st > 0) {
            //pop
            s[i] = ')';
            dfs(s, i+1, st-1, n);
        }
        if (n > 0) {
            //push
            s[i] = '(';
            dfs(s, i+1, st+1, n-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        as.clear();
        string s(2*n, 0);
        dfs(s, 0, 0, n);
        return as;
    }
};
