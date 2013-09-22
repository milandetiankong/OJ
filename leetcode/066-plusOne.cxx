class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int carry = 1;
        vector<int> ret;
        vector<int>::reverse_iterator rit = digits.rbegin();
        while (digits.rend() != rit) {
            carry += *rit;
            ret.push_back(carry % 10);
            if (carry>9) {
                carry = 1;
            } else {
                carry = 0;
            }
            ++rit;
        }
        if (carry) ret.push_back(carry);
        return vector<int>(ret.rbegin(), ret.rend());
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int>::reverse_iterator rit = digits.rbegin();
        while (digits.rend() != rit) {
            *rit += 1;
            if (*rit != 10) break;
            else *rit = 0;
            ++rit;
        }
        if (digits.rend() == rit) {
            vector<int> ret(digits.size()+1, 0);
            ret[0] = 1;
            return ret;
        }
        return digits;
    }
};
