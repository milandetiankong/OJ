class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string as(1, 1);
        string tmp(200, 0);
        int ct, len;

        while (--n) {
            tmp.clear();
            ct = 1;
            len = as.size();
            for (int i=1; i<len; ++i) {
                if (as[i] == as[i-1]) {
                    ++ct;
                } else {
                    tmp.push_back(ct);
                    tmp.push_back(as[i-1]);
                    ct = 1;
                }
            }
            tmp.push_back(ct);
            tmp.push_back(as[len-1]);
            as = tmp;
        }

        for (int i=0; i<as.size(); ++i) {
            as[i] += '0';
        }
        return as;
    }
};
