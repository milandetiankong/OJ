class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = strs.size();
        if (n==0) return string();
        
        int max = strs[0].size();
        
        for (int i=1; i<n; ++i) {
            int nj = strs[i].size();
            
            if (max > nj) max = nj;
            for (int j=0; j<nj && j<max; ++j) {
                if (strs[0][j] == strs[i][j]) continue;
                max = j;
                break;
            }
        }
        return strs[0].substr(0, max);
    }
};
