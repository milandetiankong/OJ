class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ct(n+1, 1);
        int tmp = 1;
        for (int i = 2; i <= n; ++i) {
            ct[i] = tmp;
            tmp *= i;
        }
        
        string ret(n, '0');
        string used(n+1, 0);
        --k;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (used[j] == 0) {
                    if (k >= ct[n-i]) {
                        k -= ct[n-i];
                    } else {
                        used[j] = 1;
                        ret[i] += j;
                        break;
                    }
                }
            }
        }
        return ret;
    }
};
