class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> buf(256, 0);
        
        for (int i = 0; i < T.size(); ++i) {
            ++buf[T[i]];
        }
        int ct = 0;
        for (int i = 0; i < buf.size(); ++i) {
            ct += buf[i];
        }
        int j;
        vector<int> tmp(buf);
        for (j = 0; j < S.size(); ++j) {
            if (buf[S[j]]) {
                if (tmp[S[j]] > 0) {
                    --ct;
                }
                --tmp[S[j]];
            }
            if (ct == 0) break;
        }
        if (ct) return "";
        int x = 0, y = j;
        ++j;
        for (int i = 0; i < j; ++i) {
            if (buf[S[i]]) {
                if (tmp[S[i]] == 0) {
                    x = i;
                    break;
                }
                ++tmp[S[i]];
            }
        }
        int i = x;
        for (; j < S.size(); ++j) {
            if (buf[S[j]]) {    
                --tmp[S[j]];
                while (i < j) {
                    if (buf[S[i]]) {
                        if (tmp[S[i]] == 0) break;
                        ++tmp[S[i]];
                    }
                    ++i;
                }
                if (j-i < y-x) {
                    x = i;
                    y = j;
                }
            }
        }
        return string(S.begin() + x, S.begin() + y + 1);
    }
};
