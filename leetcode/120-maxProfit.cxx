class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = prices.size();
        int ret = 0;
        if (! n) return ret;

        int m = prices[0];
        for (int i = 1; i < n; ++i) {
            ret = max(ret, prices[i] - m);
            m = min(m, prices[i]);
        }
        return ret;
    }
};
