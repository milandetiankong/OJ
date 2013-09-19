const char roman[][3] = {"", "IV", "IX", "XL", "XC", "CD", "CM"};
class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int map[256];
        map[0] = 0;
        map[1] = 4;
        map[2] = 9;
        map[3] = 40;
        map[4] = 90;
        map[5] = 400;
        map[6] = 900;
        
        map['I'] = 1;
        map['V'] = 5;
        
        map['X'] = 10;
        map['L'] = 50;
        
        map['C'] = 100;
        map['D'] = 500;
        
        map['M'] = 1000;       
        
        int n = s.size();
        for (int i=1; i<n; ++i) {
            for (int j=1; j<7; ++j) {
                if (s[i-1] == roman[j][0] && s[i] == roman[j][1]) {
                    s[i-1] = 0;
                    s[i] = j;
                    break;
                }
            }
        }
        int as = 0;
        for (int i=0; i<n; ++i) {
            as += map[s[i]];
        }
        return as;
    }
};

