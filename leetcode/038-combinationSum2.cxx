class Solution {
public:
    vector< vector<int> > as;
    vector<int> tmp;
    vector<int> cd;
    int n_cd;
    void dfs(int t, int d, int i) {
        if (t == 0) {
            // find one
            as.push_back(vector<int>(tmp.begin(), tmp.begin()+d));
            return ;
        }
        if (i == n_cd) return ;

        if (t < cd[i]) return ;
        tmp[d] = cd[i];
        dfs(t-cd[i], d+1, i+1);

        while (++i < n_cd) {
            if (cd[i] == cd[i-1]) continue;
            if (t < cd[i]) return ;
            tmp[d] = cd[i];
            dfs(t-cd[i], d+1, i+1);
        } 
    }



    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        as.clear();
        tmp = num;
        cd = num;
        sort(cd.begin(), cd.end());
        n_cd = cd.size();
        dfs(target, 0, 0);
        return as;
    }
};
