class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int step = 0;
        for (int i = n-1; i >= 0; --i) {
            if (A[i] >= step) {
                step = 1;
            } else {
                ++step;
            }
        }
        if (step == 1) return true;
        return false;
    }
};
