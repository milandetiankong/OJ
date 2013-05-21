class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0) return false;
        long long  as = 0, old = x;
        while (x) {
            as *= 10;
            as += x%10;
            x /= 10;
        }
        return as == old;
    }
};
