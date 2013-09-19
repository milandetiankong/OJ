class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> id(strs.size());
        vector<int> ct;
        map<string, int> id2key;
        int j = 0;
        for (int i = 0; i < strs.size(); ++i) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (id2key.find(tmp) == id2key.end()) {
                id2key[tmp] = j++;
                ct.push_back(1);
            } else {
                ++ct[id2key[tmp]];
            }
            id[i] = id2key[tmp];
        }
        vector<string> ret;
        for (int i = 0; i < strs.size(); ++i) {
            if (ct[id[i]] > 1) ret.push_back(strs[i]); 
        }
        return ret;
    }
};
