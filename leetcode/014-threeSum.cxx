class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector<int> > as;
        vector< int> cur(3, 0);
        int n = num.size();
        if (n < 3) return as;
        
        sort(num.begin(), num.end());
        
        int need, j, k;
        for (int i=0; i<n-2; ++i) {
            need = -num[i];
            if (i>0 && num[i]==num[i-1]) continue;
            j = i+1;
            k = n-1;
            while (j < k) {
                if (num[j]+num[k] == need) {
                    // add
                    cur[0] = num[i];
                    cur[1] = num[j];
                    cur[2] = num[k];
                    as.push_back(cur);
                    ++j;
                    --k;
                    while (num[j] == num[j-1]) ++j;
                    while (num[k] == num[k+1]) --k;
                } else if (num[j]+num[k] < need) {
                    ++j; 
                } else {
                    --k;
                }
            }
        }
        return as;
    }
};
