class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int x=0, y=n-1, mid;
        while (x <= y) {
            mid = (x+y) / 2;
            if (target == A[mid]) return mid;
            if (A[mid] >= A[x]) {
                if (target>=A[x] && target<A[mid]) y = mid-1;
                else x = mid+1;
            } else {
                if (target>A[mid] && target<=A[y]) x= mid+1;
                else y = mid-1;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int x = 0, y = n, mid;
        while (x < y) {
            mid = (x+y) / 2;
            if (target == A[mid]) return mid;
            else if (A[x] < A[mid]) {
                if (A[x]<=target && target<A[mid]) y = mid;
                else x = mid + 1;
            } else {
                if (A[mid]<target && target<=A[y-1]) x = mid + 1;
                else y = mid;
            }
        }
        return -1;
    }
};
