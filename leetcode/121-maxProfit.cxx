class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = prices.size();
        int ret = 0;
        if (n == 0) return ret;
        int buy = prices[0];
        for (int i = 1; i < n; ++i) {
            if (prices[i] > buy) {
                ret += prices[i] - buy;
            }
            buy = prices[i];
        }
        return ret;
    }
};
