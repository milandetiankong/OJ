class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< int > tmp(4, 0);
        vector< vector< int > > as;
        int n = num.size();
        if (n < 4) return as;
        
        sort(num.begin(), num.end());
        int sum, x, y;
        for (int i=0; i<n-3; ++i) {
            if (i>0 && num[i]==num[i-1]) continue;
            for (int j=i+1; j<n-2; ++j) {
                if (j>i+1 && num[j]==num[j-1]) continue;
                sum = target - num[i] - num[j];
                x = j + 1;
                y = n - 1;
                while (x < y) {
                    if (num[x]+num[y] == sum) {
                        tmp[0] = num[i];
                        tmp[1] = num[j];
                        tmp[2] = num[x];
                        tmp[3] = num[y];
                        as.push_back(tmp);
                        do {
                            ++x;
                        } while (x<y && num[x]==num[x-1]);
                        do {
                            --y;
                        } while (x<y && num[y]==num[y+1]);
                    }else if (num[x]+num[y] < sum) {
                        ++x;
                    }else {
                        --y;
                    }
                }
            }
        }
    }
};
