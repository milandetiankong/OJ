class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.        
        int n = num.size();
        int  j = n-1;
        while (--j >= 0) {
            if (num[j] < num[j+1]) break;
        }
        if (j < 0) {
            reverse(num.begin(), num.end());
            return ;
        }
        int i = n;
        while (--i > j) {
            if (num[i] > num[j]) break;
        }
        swap(num[i], num[j]);
        reverse(num.begin()+j+1, num.end());
    }
};
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n =  num.size();
        if (n < 2) return;
        
        int max = num[n-1];
        int x = n-2;
        
        for (; x>=0; --x) {
            if (num[x] < max) break;
            max = num[x];
        }
        if (x < 0) {
            reverse(num.begin(), num.end());
            return;
        }
        
        int min = max;
        int id = n-1;
        
        for (int i=n-1; i>x; --i) {
            if (num[i]>num[x] && num[i]<=min) {
                min = num[i];
                id = i;
            }
        }
        num[id] = num[x];
        num[x] = min;
        sort(num.begin()+x+1, num.end());
        return;
    }
};
