class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret(n, vector<int>(n, 0));
        int xy = 0, ab = n, ii = 1;
        while (n) {   
            for (int i = xy; i < xy+n; ++i) {
                ret[xy][i] = ii++;
            }
            
            for (int i = xy+1; i < xy+n; ++i) {
                ret[i][xy+n-1] = ii++;
            }
        
            for (int i = xy+n-2; i >= xy; --i) {
                ret[xy+n-1][i] = ii++;
            }
        
            for (int i = xy+n-2; i > xy; --i) {
                ret[i][xy] = ii++;
            }
            ++xy;
            if (n > 2) n -= 2; else n = 0;
        }
        return ret;
    }
};
