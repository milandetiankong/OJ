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

#define INF 100000
queue<pair<int, int> > wd[30];
int ans[1005];
int N, M, K, Q;
int ki;
int tt;


void insert(int id, int t) {
    static int i = 0;
    _P3(i, id, t);
    wd[i++].push(make_pair(id, t));
    if (i == N) i = 0;
}
int getMin() {
    int mid = 0;
    int mt = wd[0].front().second;
    for (int i = 1; i < N; ++i) {
        if (wd[i].front().second < mt) {
            mt = wd[i].front().second;
            mid = i;
        }
    }
    for (int i = 0; i < N; ++i) {
        wd[i].front().second -= mt;
        _P3(i, wd[i].front().first, wd[i].front().second);
    }
    tt += mt;
    ans[wd[mid].front().first] = tt;
    wd[mid].pop();
    return mid;
}

int main(int argc, char *argv[]) {
    if (argc > 1) _gDebug = true;
    cin >> N >> M >> K >> Q;
    int tmp;
    for (ki = 0; ki<K && ki<N*M; ++ki) {
        cin >> tmp;
        insert(ki, tmp);
    }
    while (ki < K) {
        int mid = getMin();
        cin >> tmp;
        _P3(ki, mid, tmp);
        wd[mid].push(make_pair(ki, tmp));
        ++ki;
    }
    _P2(tmp, tt);
    for (int i = 0; i < N; ++i) {
        tmp =  tt;
        while (! wd[i].empty()) {
            tmp += wd[i].front().second;
            ans[wd[i].front().first] = tmp;
            wd[i].pop();
        }
    }
    for (int i = 0; i < Q; ++i) {
        cin >> tmp;
        tmp = ans[tmp-1];
        if (tmp <= 9*60) {
            int hh = 8 + tmp/60; 
            int mm = tmp % 60;
            printf("%02d:%02d\n", hh, mm);
        } else {
            printf("Sorry\n");
        }
    }

    return 0;
}
