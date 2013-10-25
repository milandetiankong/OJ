class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string dp(s.size()+1, 0);
        dp[0] = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (dp[i]) {
                for (auto &x : dict) {
                    if (s.substr(i, x.size()) == x) dp[i+x.size()] = 1;
                }
            }
            if (dp[s.size()]) return true;
        }
        return false;
    }
};

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
