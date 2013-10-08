class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int i = 0, j = 0, sum= 0; 
        int n = gas.size();
        while (i < n) {
            sum += gas[j];
            sum -= cost[j];
            ++j;
            if (j == n)  j = 0;

            if (sum < 0) {
                sum = 0;
                if (j <= i) return -1;
                i = j;
            } else if (j == i) return i;
        }
        return -1;
    }
};

