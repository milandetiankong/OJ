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
        
        int sum0, sum1, sum2;
        for (int i=0; i<n; ++i) {
            if (i && num[i] == num[i-1]) continue;
            
            sum0  = num[i];
            if (sum0>0) break;
            
            for (int j=i+1; j<n; ++j) {
                if (j != i+1 && num[j] == num[j-1]) continue;
                
                sum1 = sum0 + num[j];
                if (sum1>0) break;
                
                for (int k=j+1; k<n; ++k) {
                    if (k != j+1 && num[k] == num[k-1]) continue;
                    
                    sum2 = sum1 + num[k];
                    if (sum2 == 0) {
                        cur[0] = num[i];
                        cur[1] = num[j];
                        cur[2] = num[k];
                        as.push_back(cur);
                    }
                    
                    if (sum2 > 0) break;
                }
            }
        }
        return as;
    }
};
