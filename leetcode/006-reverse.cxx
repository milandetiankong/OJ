class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int flag = 1;
        
        if (x < 0) flag = -1;
        x *= flag;
        
        int as = 0;
        while (x) {
            as *= 10;
            as += x%10;
            x /= 10;
        }
        return as * flag;
    }
};
