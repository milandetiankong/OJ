#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

bool _gDebug;
#define _P(a)  if (_gDebug) cout << #a":" << a << " "
#define _P2(a, b)   if (_gDebug) cout << #a":" << a << " "#b":" << b << endl
#define _P3(a, b, c) if (_gDebug) {\
    cout << #a":" << a << " "#b":" << b << " "#c":" << c << endl;}

#define INF 111

char buf[INF][INF];

int N, M;

int ck(int x) {
    if (x < 0) x = 0;
    if (x > N) x = N;
    return x;
}

int main(int argc, char *argv[]) {
    if (argc > 1) _gDebug = true;
    while (cin >> N >> M) {
        int ct = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                buf[i][j] = 1;
            }
        }
        int x1, y1, x2, y2;
        for (int i = 0; i < M ; ++i) {
            cin >> x1 >> y1 >> x2 >> y2;
            x1 = ck(x1);
            y1 = ck(y1);
            x2 = ck(x2);
            y2 = ck(y2);
            for (int j = x1; j < x2; ++j) {
                for (int k = y1; k < y2; ++k) {
                    if(buf[j][k]) {
                        buf[j][k] = 0;
                        ++ct;
                    }
                }
            }
        }
        cout << N*N - ct << endl;
    }
    return 0;
}
