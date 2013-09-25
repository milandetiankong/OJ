class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = prices.size();
        if (n <= 1) return 0;
        vector<int> a(n, 0);
        vector<int> b(n, 0);

        int m = prices[0];
        for (int i = 1; i < n; ++i) {
            if (prices[i] > m) a[i] = prices[i] - m;
            else m = prices[i];
            a[i] = max(a[i], a[i-1]);
        }
        
        m  = prices[n-1];
        for (int j = n-2; j >=0; --j) {
            if (prices[j] < m) b[j] = m - prices[j];
            else m = prices[j];
            b[j] = max(b[j], b[j+1]);
        }
        int ret = b[0];
        
        for (int i = 0; i < n-1; ++i) {
            if (ret < a[i]+b[i+1]) {
                ret = a[i] + b[i+1];
            }
        }
        return ret;
    }
};
