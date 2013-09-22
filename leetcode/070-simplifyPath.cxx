class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        string::iterator x = path.begin(), y = x;
        while (++y != path.end()) {
            if (*y == '/') {
                string tmp(x, y);
                if (tmp == "/..") {
                    if (! ret.empty()) {
                        ret.pop_back();
                    }
                } else if (tmp != "/" && tmp != "/.") {
                    ret.push_back(tmp);
                }
                x = y;
            }
        }
        string end(x, y);
        if (end == "/..") {
            if (! ret.empty()) ret.pop_back();
            end.clear();
        }
        else if (end == "/.") end.clear();
        else if (end == "/") end.clear();
        if (ret.empty() && end.empty()) return "/";
        string ans;
        for (int i = 0; i < ret.size(); ++i) {
            ans += ret[i];
        }
        return ans + end;
    }
};
