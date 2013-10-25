class Solution {
    unsigned long long encode(unsigned long long x) {
        unsigned long long ret = 0;
        return ret = x ^ (x>>1);
    }
    unsigned long long decode(unsigned long long x) {
        for (unsigned int mask = x>>1; mask != 0; mask = mask>>1) {
            x = x ^ mask;
        }
        return x;
    }
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function 
        vector<int> ret;
        if (n > 31) return ret;
        int ct = 1 << n;
        for (int i = 0; i < ct; ++i) {
            ret.push_back(encode(i));
        }
        return ret;
    }
};
