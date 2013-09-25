class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = triangle.size()-2; i>=0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (triangle[i+1][j] < triangle[i+1][j+1]) {
                    triangle[i][j] += triangle[i+1][j];
                } else {
                    triangle[i][j] += triangle[i+1][j+1];
                }
            }
        }
        return triangle[0][0];
    }
};
