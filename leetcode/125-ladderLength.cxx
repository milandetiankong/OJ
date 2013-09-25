class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = 2;
        if (start == end) return 0;
        vector<string> wd;
        unordered_map<string, int> mf;
        //must be unordered_map
        wd.push_back(start);
        mf[start] = 0;
        wd.push_back(end);
        mf[end] = 1;
        for (unordered_set<string>::iterator j = dict.begin(); j != dict.end(); ++j) {
            wd.push_back(*j);
            mf[*j] = n;
            ++n;
        }
        mf[end] = 1;
        
        string f;
        int id;


        queue<int> q, p;
        vector<char> used(n, 0);
        int tmp;
        q.push(0);
        used[0] = 1;
        int step = 1;
        while (! q.empty()) {
            tmp = q.front();
            q.pop();
            if (tmp == 1) return step;
            for (int j = 0; j < wd[tmp].size(); ++j) {
                f = wd[tmp];
                for (char k = 'a'; k <= 'z'; ++k) {
                    f[j] = k;
                    if (mf.find(f) != mf.end()) {
                        id = mf[f];
                        if (used[id] == 0) {
                            used[id] = 1;
                            p.push(id);
                        }
                    }
                }
            }
            if (q.empty()) {
                ++step;
                q.swap(p);
            }
        }
        return 0;
    }
};

class Solution {
    char oneStep(string &a, string &b) {
        int ct = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) ++ct;
        }
        return ct<2 ? 1 : 0;
    }
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = 2;
        if (start == end) return 0;
        vector<string> wd;
        wd.push_back(start);
        wd.push_back(end);
        for (unordered_set<string>::iterator j = dict.begin(); j != dict.end(); ++j) {
            wd.push_back(*j);
            ++n;
        }
        int ct = 0;

        queue<int> q, p;
        vector<char> used(n, 0);
        int tmp;
        q.push(0);
        used[0] = 1;
        int step = 1;
        while (! q.empty()) {
            tmp = q.front();
            q.pop();
            if (tmp == 1) return step;
            for (int i = 0; i < n; ++i) {
                if (used[i]==0 && OneStep(wd[tmp], wd[i])) {
                    used[i] = 1;
                    p.push(i);
                }
            }
            if (q.empty()) {
                ++step;
                q.swap(p);
            }
        }
        return 0;
    }
};
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = 2;
        if (start == end) return 0;
        vector<string> wd;
        map<string, int> mf;
        wd.push_back(start);
        mf[start] = 0;
        wd.push_back(end);
        mf[end] = 1;
        for (unordered_set<string>::iterator j = dict.begin(); j != dict.end(); ++j) {
            wd.push_back(*j);
            mf[*j] = j;
            ++n;
        }
        vector<vector<bool> > mw(n, vector<bool>(n, 0));
        string tmp;
        int id;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < wd[i].size(); ++j) {
                for (char k = 'a'; k <= 'z'; ++k) {
                    tmp = wd[i];
                    tmp[j] = k;        
                    if (mf.find(tmp) != mf.end()) {
                        id = mf[tmp];
                    }
                }
            }
        }

        queue<int> q, p;
        vector<char> used(n, 0);
        int tmp;
        q.push(0);
        used[0] = 1;
        int step = 1;
        while (! q.empty()) {
            tmp = q.front();
            q.pop();
            if (tmp == 1) return step;
            for (int i = 0; i < n; ++i) {
                if (used[i]==0 && mw[i][j])) {
                    used[i] = 1;
                    p.push(i);
                }
            }
            if (q.empty()) {
                ++step;
                q.swap(p);
            }
        }
        return 0;
    }
};
