class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = height.size();
        int min, ret = 0, tmp;
        for (int i = 0; i < n; ++i) {
            min = height[i];
            if (min > ret) ret = min;
            for (int j = i+1; j < n; ++j) {
                if (height[j] < min) min = height[j];
                tmp = min * (j - i + 1);
                if (tmp > ret) ret = tmp;
            }
        }
        return ret;
    }
};
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = height.size();
        int ret = 0, tmp, j, k;
        for (int i = 0; i < n; ++i) {
            tmp = height[i];
            j = i - 1;
            while (j>=0) {
                if (height[j] < tmp) break;
                --j;
            }
            k = i + 1;
            while (k < n) {
                if (height[k] < tmp) break;
                ++k;
            }
            tmp *= (k - j - 1);
            if (tmp > ret) ret = tmp;
        }
        return ret;
    }
};
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        height.push_back(0);
        int n = height.size();
        int ret = 0, i = 0, tmp;
        stack<int> s;
        while (i < n) {
            if (s.empty() || height[i] >= height[s.top()]) {
                s.push(i++);
            } else {
                tmp = height[s.top()];
                s.pop();
                if (s.empty()) tmp *= i;
                else tmp *= (i - s.top() - 1);
                if (tmp > ret) ret = tmp;
            }
        }
        return ret;
    }
};
