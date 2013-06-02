char phone[][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz", ""};
class Solution {
public:
    string s;
    string tmp;
    int n;
    void next(vector< string > &as, int i) {
        if (i == n) {
            as.push_back(tmp);
            return ;
        }
        char num = s[i] - '0';
        int j = 0;
        while (phone[num][j]) {
            tmp[i] = phone[num][j];
            next(as, i+1);
            ++j;
        }
    }
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< string > as;
        n = digits.size();
        tmp = digits;
        s = digits;
        next(as, 0);
        return as;
    }
};
