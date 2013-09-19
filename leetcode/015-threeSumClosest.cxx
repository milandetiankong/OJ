class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int min = ~(1<<31);
        int sum, as, cur;
        int n = num.size();
        
        sort(num.begin(), num.end());
        
        for (int i=0; i<n; ++i) {
            if (num[i] >=0 && num[i]-target >= min) break;
            for (int j=i+1; j<n; ++j) {
                if (num[j]>=0 && num[i]+num[j]-target >= min) break; 
                for (int k=j+1; k<n; ++k) {
                    sum = num[i] + num[j] + num[k];
                    cur = sum - target;
                    if (num[k]>=0 && cur > min) break;
                    if (cur < 0) cur = -cur;
                    if (cur < min) {
                        as = sum;
                        min = cur;
                    }
                }
            }
        }
        return as;
    }
};
