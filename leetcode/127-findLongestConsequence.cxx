class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_set<int> m;
        for (int i = 0; i < num.size(); ++i) m.insert(num[i]);
        int tmp, maxCt = 0;
        for (int i = 0; i < num.size(); ++i) {
            tmp = num[i];
            int ct  = 1;
            while (true) {
                --tmp;
                if (m.find(tmp) == m.end()) break;
                m.erase(tmp);
                ++ct;
            }
            tmp = num[i];
            while (true) {
                ++tmp;
                if (m.find(tmp) == m.end()) break;
                m.erase(tmp);
                ++ct;
            }
            if (ct > maxCt) maxCt = ct;
        }
        return maxCt;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        unordered_set<int> s;
        int ret = 0;
        for (auto i : num) s.insert(i);
        for (auto i : num) {
            int ct = 1;
            int tmp = i;
            while (s.find(--tmp) != s.end()) {
                ++ ct;
                s.erase(tmp);
            }
            tmp = i;
            while (s.find(++tmp) != s.end()) {
                ++ ct;
                s.erase(tmp);
            }
            if (ret < ct) ret = ct;
        }
        return ret;
    }
};
