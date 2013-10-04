class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = ratings.size();
        vector<int> candy(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i-1]) {
                candy[i] = candy[i-1] + 1;
            }
        }
        int ret = candy[n-1];
        for (int i = n-2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1] && candy[i] <= candy[i+1]) {
                candy[i] = candy[i+1] + 1;
            }
            ret += candy[i];
        }
        return ret;
    }
};
