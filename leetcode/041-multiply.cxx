class Solution {
public:
    void mymulty(string &a, int b) {
        // assume b < 10;
        int max = a.size() + 1;
        a.resize(max);

        int carry = 0;
        for (int i=0; i<max; ++i) {
            carry += a[i] * b;
            a[i] = carry % 10;
            carry /= 10;
        }
        while ( ! a[--max]) {
            ;   // empty
        }
        a.resize(max+1); 
    }
    void myadd(string &a, string &b) {
        int an = a.size();
        int bn = b.size();
        int max = an > bn ? an : bn;
        ++max; 
        a.resize(max);
        b.resize(max);

        int carry = 0;
        for (int i=0; i<max; ++i) {
           carry += a[i] + b[i]; 
           a[i] = carry%10;
           carry /= 10;
        }
        while ( ! a[--max])   {
            ;   //empty
        }
        a.resize(max + 1);
    }
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        reverse(num1.begin(), num1.end()); 
        reverse(num2.begin(), num2.end());
        int an = num1.size();
        int bn = num2.size();

        for (int i=0; i<an; ++i) {
            num1[i] -= '0';
        }
        string as(0, 0);
        string base;

        for (int i=0; i<bn; ++i) {
            num2[i] -= '0';
            string tmp = base + num1;
            mymulty(tmp, num2[i]);
            myadd(as, tmp);
            base.push_back(0);
        }

        int n = as.size();
        if (! n) {
            as.push_back(0);
            ++n;
        }
        for (int i=0; i<n; ++i) {
            as[i] += '0';
        }

        reverse(as.begin(), as.end());
        return as;
    }
};
