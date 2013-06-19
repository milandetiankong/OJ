class Solution {
public:
    vector<int> cd;
    vector< vector<int> > as;
    vector<int> tmp;
    int cd_n;

    void dfs(int t, int d, int i) {
        if (t == 0)  {
            // find one
            as.push_back(vector<int>(tmp.begin(), tmp.begin()+d));
            return;
        }

        if (i == cd_n) return;

        tmp[d] = cd[i];
        if(t-cd[i] < 0) return;
        dfs(t-cd[i], d+1, i);
        while (++i < cd_n) {
            if (cd[i] != cd[i-1]) {
                tmp[d] = cd[i];
                if(t-cd[i] < 0) return;
                dfs(t-cd[i], d+1, i);
            }
        }
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        cd = candidates;
        sort(cd.begin(), cd.end());
        cd_n = cd.size();

        as.clear();
        tmp.resize(target/cd[0]+1);

        dfs(target, 0, 0);
        return as;
    }
};
