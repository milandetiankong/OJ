const char roman[][10][5] = { {"", "I","II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                            {"", "X","XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                            {"", "C","CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                            {"", "M","MM", "MMM", "M*", "*", "*M", "*MM", "*MMM", "M*"} };
class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int buf[6];
        int bi = 0;
        while (num) {
            buf[bi++] = num%10;
            num /= 10;
        }
        --bi;
        string as;
        while (bi>=0) {
            as += roman[bi][buf[bi]];
            --bi;
        }
        return as;
    }
};

