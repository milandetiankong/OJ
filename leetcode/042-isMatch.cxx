class Solution {
 public:
 bool isMatch(const char *s, const char *p) {
     // Start typing your C/C++ solution below
     // DO NOT write int main() function
     string np(p);
     int j = 0;
     int cnt = 0;
     for (int i = 1; i < np.size(); ++i) {
         if (np[i] == '*' && np[j] == '*') continue;
         np[++j] = np[i];
     }
     const char * tmp = p;
     while (*tmp) {
         if (*tmp != '*') ++cnt;
            ++tmp;
     }
     if (*p == 0) j = -1;
 
     int k = 0;
     while (s[k]) ++k;
     if (cnt > k) return false;
     ++k;
     string ns(k, 0);
 
     for (int i = 0; i < k; ++i) ns[i] = 0;
     ns[0] = 1;
     for (int i = 0; i <= j; ++i) {
         if (np[i] == '*') {
             for (int l = 0; l < k; ++l) {
                 if (ns[l-1]==1) ns[l] = 1;
             }
         } else {
             for (int l = k-1; l >= 1; --l) {
                 if (np[i] == s[l-1] || np[i] == '?') {
                     ns[l] = ns[l-1];
                 } else {
                     ns[l] = 0;
                 }
             }
             ns[0] = 0;
         } 
     }
     return  ns[k - 1];
 }
 };
