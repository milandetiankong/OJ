class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        int p, q, len, tmp, k, mod, sp;
        p = 0; len = -1;
        for (q = p; q < words.size(); ++q) {
            tmp = words[q].size() + 1;
            if (tmp + len > L) {
                if (q - p > 1) {
                    k = (L - len) / (q - p - 1);
                    mod = (L - len) % (q - p - 1);
                }
                string item(words[p]);
                ++p;
                while (p != q) {
                    sp = k+1;
                    if (mod) {
                        ++sp;
                        --mod;
                    }
                    item += string(sp, ' ');
                    item += words[p];
                    ++p;
                }
                if (item.size() < L) {
                    item.resize(L, ' ');
                }
                ret.push_back(item);
                len = tmp - 1;
            } else {
                len += tmp;
            }
        }
        string item(words[p++]);
        while (p != q) {
            item += " " + words[p++];
        }
        item.resize(L, ' ');
        ret.push_back(item);
        return ret;
    }
};
