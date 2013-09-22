class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int x = 0, mid, y = n;

        while (x < y) {
            mid = (x + y)/2;
            if (A[mid] == target) return true;
            if (A[x] == target) return true;
            if (A[y-1] == target) return true;
            if (A[x] < A[mid]) {
                if (A[x] < target && target < A[mid]) y = mid;
                else x = mid + 1;
            } else if (A[mid] < A[y-1]) {
                if (A[mid] < target && target < A[y-1]) x = mid + 1;
                else y = mid;
            } else {
                ++x;
                --y;
            }
        }
        return false;
    }
};
