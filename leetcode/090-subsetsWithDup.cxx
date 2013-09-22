class Solution {
    int n;
    vector<int> item;
    vector<int> used;
    vector<vector<int> > ret;
    void dfs(vector<int> &S, int step, int start) {
        ret.push_back(item);
        if (step == n) return ;
        char flag = 0;
        int last;
        for (int i = start; i < n; ++i) {
            if (used[i]) continue;
            if (flag && last == S[i]) continue;
            used[i] = 1;
            item.push_back(S[i]);
            flag = 1;
            last = S[i];
            dfs(S, step+1, i+1);
            item.pop_back();
            used[i] = 0;
        }
    }
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        item.clear();
        ret.clear();
        n = S.size();
        used.assign(n, 0);
        sort(S.begin(), S.end());
        dfs(S, 0, 0);
        return ret;
    }
};
