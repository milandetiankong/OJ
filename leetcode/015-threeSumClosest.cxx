class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int min = INT_MAX;
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


class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int gap = INT_MAX;
        int sum, tmp, ret;
        int n = num.size();

        if (n < 3) return 0;
        sort(num.begin(), num.end());
        
        for (int i=0; i<n-2; ++i) {
            sum = target - num[i];
            int l = i+1, r = n-1;
            while(l < r) {
                tmp = num[l] + num[r];
                if (abs(sum-tmp) < gap) {
                    ret = num[i] + tmp;
                    gap = abs(sum-tmp);
                }
                if (tmp < sum) ++l;
                else if (tmp > sum) --r;
                else break;
            }
        }
        return ret;
    }
};

