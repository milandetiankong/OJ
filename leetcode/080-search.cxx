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

class Solution {
public:
    bool search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int x = 0, y = n, mid;
        while (x < y) {
            mid = (x+y) / 2;
            if (target == A[mid]) return true;
            else if (A[x] < A[mid]) {
                if (A[x]<=target && target<A[mid])  y = mid;
                else x = mid + 1;
            } else if (A[mid] < A[x]) {
                if (A[mid]<target && target<=A[y-1]) x = mid + 1;
                else y = mid;
            } else {
                ++x;
            }
        }
        return false;
    }
};
