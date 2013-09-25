class Solution {
    vector<string> wd;
    vector<vector<int> > mwd;
    int n;
    int id0, id1;
    vector<vector<int> > prev;
    vector<vector<string> > ret;
    vector<string> item;
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, int> s2id;
        wd.clear();
        mwd.clear();
        dict.insert(start);
        dict.insert(end);
        n = 0;
        for (auto it = dict.begin(); it != dict.end(); ++it) {
            s2id[*it] = n;
            wd.push_back(*it);
            ++n;
        }

        mwd.resize(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < wd[i].size(); ++j) {
                string tmp = wd[i];
                for (int k = 'a'; k <= 'z'; ++k) {
                    tmp[j] = k;
                    if (s2id.find(tmp) != s2id.end()) {
                        mwd[i].push_back(s2id[tmp]);
                    }
                }
            }
        }
        id0 = s2id[start];
        id1 = s2id[end];
        queue<int> que, que1;
        vector<int> used(n);
        pre.clear();
        prev.resize(n);
        int step = 2, tmp;
        que.push(id0);
        used[id0] = 1;
        while(not que.empty()){
            tmp = que.front(); que.pop();
            if(tmp == id1) break;
            for(int i = 0; i < mwd[tmp].size(); ++i){
                int v = mwd[tmp][i];
                if(used[v] == 0){
                    prev[v].push_back(tmp);
                    used[v] = step;
                    que1.push(v);
                }else if(used[v] == step){
                    prev[v].push_back(tmp);
                }
            }
            if (que.empty()) {
                swap(que1, que);
                ++step;
            }
        }
        ret.clear();
        item.clear();
        dfs(id1);
        return ret;
    }
    void dfs(int id){
        item.push_back(wd[id]);
        if (id == id0) ret.push_back(vector<string>(item.rbegin(), item.rend()));
        else for(int i = 0; i < prev[id].size(); i++) dfs(prev[id][i]);
        item.pop_back();
    }
};

