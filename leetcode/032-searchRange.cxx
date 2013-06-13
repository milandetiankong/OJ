class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int x=0, y=n-1, mid;
        vector<int> as(2, 0);
        
        while (x < y) {
            mid = (x+y) / 2; 
            if (target <= A[mid]) {
                y = mid;
            } else {
                x = mid+1;
            }
        }
        if (A[x] == target) {
            as[0] = x;
        } else {
            // not find
            as[0] = -1;
            as[1] = -1;
            return as;
        }

        y = n-1; 
        while (x < y) {
            mid = (x+y+1) / 2; 
            if (target >= A[mid]) x = mid;
            else y = mid-1;
        }
        as[1] = x;
        return as;
    }
};
