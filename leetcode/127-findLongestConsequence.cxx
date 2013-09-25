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
