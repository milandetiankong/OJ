#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef unsigned int uint;

struct tuple3 {
    int a, b, d;
    bool operator<(const tuple3 & t) const {
        return d < t.d;
    }
};

int node[1003];

int f(int x) {
    if (node[x] == x) return x;
    node[x] = f(node[x]);
    return node[x];
}

int main(void) {
    int n, m;
    tuple3 tmp;
    while (cin >> n >> m) {
        vector<tuple3> edge;
        for (int i = 0; i < m; ++i) {
            //cin >> tmp.a >> tmp.b >> tmp.d;
            scanf("%d %d %d", &tmp.a, &tmp.b, &tmp.d);
            edge.push_back(tmp);
        }
        sort(edge.begin(), edge.end());
        for (int i = 1; i <= n; ++i) {
            node[i] = i;
        }
        int ct = 1, a, b;
        int ret = 0;
        for (int i = 0; i < m; ++i) {
            a = f(edge[i].a);
            b = f(edge[i].b);
            if (a == b) continue;
            node[a] = b;
            ret += edge[i].d;
            ++ct;
            if (ct == n) break;
        }
        if (ct == n) {
            //cout << ret << endl;
            printf("%d\n", ret);
        } else {
            //cout << "no" << endl;
            printf("no\n");
        }
    }

    return 0;
}

