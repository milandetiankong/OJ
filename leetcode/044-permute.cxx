class Solution {
    vector<int> item;
    vector<vector<int> > ret;
    vector<int> used;
    int n;
    void dfs(vector<int> &num, int k) {
        if (k == n) {
            ret.push_back(item);
            return ;
        }
        for (int i = 0; i < n; ++i) {
            if (used[i] ==0) {
                item.push_back(num[i]);
                used[i] = 1;
                dfs(num, k+1);
                used[i] = 0;
                item.pop_back();
            }
        }
    }
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        n = num.size();
        ret.clear();
        item.clear();
        used.clear();
        used.resize(n);
        dfs(num, 0);
        return ret;
    }
};
