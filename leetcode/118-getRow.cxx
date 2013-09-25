class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function        
        vector<int> ret;
        if (rowIndex < 0) return ret;
        ret.push_back(1);
        if (rowIndex == 0) return ret;
        vector<int> p(rowIndex+1, 1);
        vector<int> q(rowIndex+1, 1);
        for (int i = 1; i <= rowIndex; ++i) {
            q[i] = 1;
            for (int j = i+1; j <= rowIndex; ++j) {
                q[j] = p[j-1] + q[j-1];
            }
            ret.push_back(q[rowIndex]);
            q.swap(p);
        }
    }
};
