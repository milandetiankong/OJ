class Solution {
    string s;
    unordered_set<string> dict;
    bool startWith(int i, const string &t) {
        return t == s.substr(i, t.size());
    }
    bool dfs(int d) {
        if (d == s.size()) return true;
        for (auto it = dict.begin(); it != dict.end(); ++it) {
            if (startWith(d, *it) && dfs(d+(*it).size())) return true;
        }
        return false;
    }
public:
    bool wordBreak(string ss, unordered_set<string> &dd) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        dict = dd;
        vector<string> tmp;
        for (auto it = dict.begin(); it != dict.end(); ++it) {
            tmp.push_back(*it);
        }
        sort(tmp.rbegin(), tmp.rend());
        for (int i = 0; i < tmp.size(); ++i) {
            s = tmp[i];
            dict.erase(tmp[i]);
            if (!dfs(0)) dict.insert(tmp[i]);
        }
        s = ss;
        return dfs(0);
    }
};
