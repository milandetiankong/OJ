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
