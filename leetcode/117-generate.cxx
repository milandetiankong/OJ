class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        vector<int> item;
        vector<int> tmp;
        if (numRows == 0) return ret;
        item.push_back(1);
        ret.push_back(item);
        if (numRows == 1) return ret;
        for (int i = 1; i < numRows; ++i) {
            tmp.push_back(1);
            for (int j = 1; j < item.size(); ++j) {
                tmp.push_back(item[j-1] + item[j]);
            }
            tmp.push_back(1);
            ret.push_back(tmp);
            item.swap(tmp);
            tmp.clear();
        }
        return ret;
    }
};
