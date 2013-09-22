class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string::reverse_iterator pa = a.rbegin();
        string::reverse_iterator pb = b.rbegin();
        char x, y, carry = 0;
        string ret;
        while (pa != a.rend() || pb != b.rend()) {
            x = y = '0';
            if (pa != a.rend()) x = *pa++;
            if (pb != b.rend()) y = *pb++;
            carry += x - '0' + y - '0';
            ret.push_back('0' + carry%2);
            if (carry > 1) carry = 1;
            else carry = 0;
        }
        if (carry) ret.push_back('0' + carry);
        string::reverse_iterator pr = ret.rbegin();
        while (pr != ret.rend()) {
            if (*pr == '1') break;
            ++pr;
        }
        if (pr == ret.rend()) return string("0");
        return string(pr, ret.rend());
    }
};
