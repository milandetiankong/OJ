#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;


#define INF 111

int st[INF*INF];
int pos[INF];
int len[INF];

int N, M , K;

int findst(int num) {
    int p = 0, ct = 0;
    int i;
    for (i = 1; i <= N*N; ++i) {
        if (st[i]) {
            p = i;
            ct = 0;
        } else {
            ++ct;
            if (ct == num) break;
        }
    }
    if (i > N*N) return 0;
    ++p;
    for (i = p; i < p+num; ++i) {
        st[i] = 1;
    }
    return p;
}

int solve() {
    string op;
    int id, num;
    for (int ki = 0; ki < K; ++ki) {
        cin >> op >> id;
        if ("out" == op) {
            if (pos[id]) {
                for (int j = pos[id]; j < pos[id]+len[id]; ++j) {
                    st[j] = 0;
                }
                pos[id] = 0;
            }
        } else { 
            cin >> num;
            if (pos[id]) {
                cout << "no" << endl;
            } else {
                pos[id] = findst(num); 
                len[id] = num;
                if (pos[id]) {
                    cout << "yes" << endl;
                } else {
                    cout << "no" << endl;
                }
            }
        }
    }
    return 0;
}

int main(void) {
    while (cin >> N >> M >> K) {
        for (int i = 0; i <= N*N; ++i) {
            st[i] = 0;
        }
        for (int i = 0; i <= M; ++i) {
            pos[i] = 0;
        }
        solve();
    }

    return 0;
}