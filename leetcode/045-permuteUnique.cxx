class Solution {
    vector<vector<int> > ret;
    vector<int> item;
    map<int, int> used;
    int n;
    void dfs(int k) {
        if (k == n) {
            ret.push_back(item);
            return ;
        }
        for (map<int, int>::iterator it = used.begin(); it != used.end(); ++it) {
            if (it->second) {
                item.push_back(it->first);
                --it->second;
                dfs(k+1);
                ++it->second;
                item.pop_back();
            }
        }
    }
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        n =  num.size();
        used.clear();
        for (int i = 0; i < n; ++i) {
            ++used[num[i]];
        }
        ret.clear();
        item.clear();
        dfs(0);
        return ret;
    }
};
