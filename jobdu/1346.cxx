#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> & a, const pair<int, int> & b) {
    if (a.second < b.second) return true;
    if (a.second == b.second) return a.first > b.first;
    return false;
}

int main(void) {
    int n, m;
    while ( cin >> n >> m) {        
        vector<pair<int, int> > id;
        int a, b;
        for (int i = 0; i < n; ++i) {
            cin >> a >> b;
            id.push_back(pair<int, int>(a, b));
        }
        a = min(m, n);
        make_heap(id.begin(), id.end(), cmp);
        for (int i = 0; i < a; ++i) {
            cout << id[0].first << endl;
            pop_heap(id.begin(), id.end(), cmp);
            id.pop_back();
        }
    }
    return 0;
}
