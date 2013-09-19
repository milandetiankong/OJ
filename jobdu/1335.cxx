#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool _gDebug;
#define _P(a)  if (_gDebug) cout << #a":" << a << " "
#define _P2(a, b)   if (_gDebug) cout << #a":" << a << " "#b":" << b << endl
#define _P3(a, b, c) if (_gDebug) {\
    cout << #a":" << a << " "#b":" << b << " "#c":" << c << endl;}

#define INF 150

int ans = -1;
int N;
int map[INF][INF];
int ct[INF][INF];

void dfs(int x, int y, int s) {
    if (ans>0 && s >= ans) {
        return ;
    }
    if (x== N && y==N) {
        if (ans <= 0)  ans = s;
        else if (ans > s) {
            ans = s;
        }
        return ;
    }
    map[x][y] = 1;
    ++s;
    if (!map[x+1][y]) dfs(x+1,  y, s);
    if (!map[x-1][y]) dfs(x-1,  y, s);
    if (!map[x][y+1]) dfs(x,  y+1, s);
    if (!map[x][y-1]) dfs(x,  y-1, s);
    map[x][y] = 0;
}

int main(int argc, char *argv[]) {
    if (argc > 1) _gDebug = true;

    while (cin >> N) {
        for (int i = 0; i <= N+1; ++i) {
            for (int j = 0; j <= N+1; ++j) {
                map[i][j] = 1;
                ct[i][j] = 0;
            }
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                cin >> map[i][j];
            }
        }
        if (map[1][1] || map[N][N]) {
            cout << -1 << endl;
            continue;
        }
        if (N == 1) {
            cout << 0 << endl;
            continue;
        }
        ans = -1;
        dfs(1, 1, 0);
        if ( ans<=0 ) cout << -1 << endl;
        else cout << ans << endl;
    }

    return 0;
}
int main2(int argc, char *argv[]) {
    if (argc > 1) _gDebug = true;
    while (cin >> N) {
        for (int i = 0; i <= N+1; ++i) {
            for (int j = 0; j <= N+1; ++j) {
                map[i][j] = 1;
                ct[i][j] = 0;
            }
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                cin >> map[i][j];
            }
        }
        if (map[1][1] || map[N][N]) {
            cout << -1 << endl;
            continue;
        }
        if (N == 1) {
            cout << 0 << endl;
            continue;
        }
        queue<pair<int, int> > q;
        ct[1][1] = 1;
        q.push(make_pair(1, 1));
        int xy, x, y, tmp;
        while (! q.empty()) {
            _P3(xy, N, tmp);
            x = q.front().first;
            y = q.front().second;
            tmp = ct[x][y] + 1;
            if (! map[x+1][y]) {
                _P3(x, y, map[x+1][y]);
                if (!ct[x+1][y] || ct[x+1][y]>tmp) {
                    ct[x+1][y] = tmp;
                    q.push(make_pair(x+1, y));
                }
            }
            if (! map[x-1][y]) {
                _P3(x, y, map[x-1][y]);
                if (!ct[x-1][y] || ct[x-1][y]>tmp) {
                    ct[x-1][y] = tmp;
                    q.push(make_pair(x-1, y));
                }
            }
            if (! map[x][y+1]) {
                _P3(x, y, map[x][y+1]);
                if (!ct[x][y+1] || ct[x][y+1]>tmp) {
                    ct[x][y+1] = tmp;
                    q.push(make_pair(x, y+1));
                }
            }
            if (! map[x][y-1]) {
                _P3(x, y, map[x][y-1]);
                if (!ct[x][y-1] || ct[x][y-1]>tmp) {
                    ct[x][y-1] = tmp;
                    q.push(make_pair(x, y-1));
                }
            }
            q.pop();
        }
        int ret = ct[N][N];
        if (map[1][1]) ret = 0;
        if (ret) {
            cout << ret -1 << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
