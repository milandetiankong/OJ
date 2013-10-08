class Solution {
    string ss;
    unordered_set<string> dd;
    vector<string> item;
    vector<string> ret;
    bool startWith(int i, const string &x) {
        return ss.substr(i, x.size()) == x;
    }
    void dfs(int i) {
        if (i == ss.size()) {
            string tmp;
            for (int i = 0; i < item.size(); ++i) {
                tmp += item[i] + " ";
            }
            tmp.resize(tmp.size()-1);
            ret.push_back(tmp);
            return ;
        }
        for (auto it = dd.begin(); it != dd.end(); ++it) {
            if (startWith(i, *it)) {
                item.push_back(*it);
                dfs(i + (*it).size());
                item.pop_back();
            }
        }
    }
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ss = s;
        dd =dict; 
        item.clear();
        ret.clear();
        vector<char> m(256, 0);
        for (int i = 0;  i<s.size(); ++i) {
            m[s[i]] = 1;
        }
        for (auto it = dict.begin(); it != dict.end(); ++it) {
            for (int j = 0; j < (*it).size(); ++j) {
                m[(*it)[j]] = 0;
            }
        }
        for (int i = 0; i < m.size(); ++i) {
            if (m[i]) return ret;
        }

        dfs(0);
        return ret;
    }
};
