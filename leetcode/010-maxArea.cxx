class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max = 0;
        int n = height.size();
        int i =0, j=n-1;
        int tmp;
        while (i < j) {
            tmp = j - i;
            if (height[i] < height[j]) {
                tmp *= height[i++];
            } else {
                tmp *= height[j--];
            }
            if (max < tmp) max = tmp;
        }
        return max;
    }
};
