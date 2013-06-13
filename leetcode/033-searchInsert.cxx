class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int x=0, y=n-1, mid;
        while (x < y) {
            mid = (x+y) / 2;
            if (A[mid] == target) return mid;
            else if (A[mid] < target) x = mid+1;
            else  y = mid;
        }
        if (target <= A[x]) return x;
        return x+1;
    }
};

