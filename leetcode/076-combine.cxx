class Solution {
        int n, k;
        vector<vector<int> > ret;
        vector<int> item, used;
        void dfs(int step) {
            if (step == k) {
                ret.push_back(item);
                return ;
            }
            int start = 1;
            if (step != 0) start = item[step-1] + 1;
            for (int i = start; i <= n; ++i) {
                if (used[i]) continue;
                used[i] = 1;
                item[step] = i;
                dfs(step+1);
                used[i] = 0;
            }
        }
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        this->n = n;
        this->k = k;
        ret.clear();
        item.assign(k, 0);
        used.assign(n+1, 0);
        dfs(0); 
        return ret;
    }
};
