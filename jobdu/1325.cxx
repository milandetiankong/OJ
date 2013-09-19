#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


#define INF 10004
int f[INF];
vector<int> ca;
vector<int> cb;


int gf(int i) {
    if (f[i] == i) return i;
    f[i] = gf(f[i]);
    return f[i];
}

int main(int argc, char *argv[]) {
    int n, m, k, a, b;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        ca.push_back(a);
        cb.push_back(b);
    }
    int id;
    for (int i = 0; i < k; ++i) {
        cin >> id;
        for (int j = 1; j <= n; ++j) {
            f[j] = j;
        }
        for (int j = 0; j < m; ++j) {
            if ( id != ca[j] && id != cb[j]) {
                f[gf(cb[j])] = gf(ca[j]);
            }
        }
        int ct = 0;
        for (int j = 1; j <= n; ++j) {
            if (j == f[j]) ++ct;
        }
        cout << ct - 2  << endl;
    }

    return 0;
}
