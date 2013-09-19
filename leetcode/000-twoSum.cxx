class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> tmp(numbers.begin(), numbers.end());
        sort(tmp.begin(), tmp.end());
        
        int n = tmp.size();
        int i = 0, j = n-1;
        int a1, a2;
        
        while (1) {
            a1 = tmp[i] + tmp[j];
            if (a1 == target) {
                a1 = tmp[i];
                a2 = tmp[j];
                break;
            } else if (a1 < target) {
                ++i;
            } else {
                --j;
            }
        }
        vector<int> as;
        i = 0;
        while (1) {
            if (numbers[i] == a1) {
                as.push_back(i+1);
                if (as.size() == 2) break;
            }else if (numbers[i] == a2) {
                as.push_back(i+1);
                if (as.size() ==2) break;
            }
            ++i;
        }
        return as;
    }
};
