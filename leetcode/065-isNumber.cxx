class Solution {
    bool isDot(const char *s, const char *dot,  const char *p) {
        if (*(dot+1) == '+' ||*(dot+1) == '-') return false;
        if (*s == '+' || *s == '-') ++s;
        if (s==dot) return isInt(dot+1, p);
        if (dot+1 == p) return isInt(s, dot);
        return isInt(s, dot) && isInt(dot+1, p);
    }
    bool isInt(const char *s, const char *p) {
        if (*s == '+' || *s == '-') ++s;
        if (s >= p) return false;
        while (s != p) {
            if (*s<'0' || *s>'9') return false;
            ++s;
        }
        return true;
    }
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const char * p = s, *q;
        while (*p == ' ') ++p;
        if (*p == 0) return false;
        q = p;
        while (*q) ++q;
        while (*(q-1) == ' ') --q;
        const char *i = p;
        const char *dot = 0, *e = 0;
        while (i != q) {
            if (*i == '.') {
                if (dot) return false;
                dot = i;
            }
            if (*i == 'e' || *i == 'E') {
                if (e) return false;
                e = i;
            }
            ++i;
        }
        if (dot==0 && e==0) return isInt(p, q);
        else if (dot==0 && e) return isInt(p, e) && isInt(e+1, q);
        else if (dot && e==0) return isDot(p, dot, q);
        if (dot >= e) return false;
        return isDot(p, dot, e) && isInt(e+1, q);
    }
};
