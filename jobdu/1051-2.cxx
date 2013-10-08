#include <stdio.h>
#include <stdint.h>
#include <algorithm>


using namespace std;

int n, m;
struct Edge{
    int a, b, c;
    bool operator<(const Edge & rhs) const {
        return c < rhs.c;
    }
}buf[1000006];

int p[10004];

int f(int x) {
    if (p[x] == x) return x;
    p[x] = f(p[x]);
    return p[x];
}

int main(void) {
    int a, b, c;
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 1; i <= n; ++i) {
            p[i] = i;
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &buf[i].a, &buf[i].b, &buf[i].c);
        }
        sort(buf, buf+m);
        int i, x, y;
        for (i = 0; i < m; ++i) {
            x = f(buf[i].a);
            y = f(buf[i].b);
            if (x == y) continue;
            p[x] = y;
            if (f(1)==n || f(n) == 1) break;
            if (f(1) != 1) {
                p[f(1)] = 1;
                p[1] = 1;
            }
            if (f(n) != n) {
                p[f(n)] = n;
                p[n] = n;
            }
        }
        if (f(1) == n || f(n) == 1) {
            printf("%d\n", buf[i].c);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}



/*

int bd[10002][10002];
bool used[10004];
unsigned int cost[1002];
int da(void) {
    int a, b, c;
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                bd[i][j] = -1;
            }
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &a, &b, &c);
            if (bd[a][b] < 0 || c < bd[a][b]) {
                bd[a][b] = bd[b][a] = c;
            }
        }
        for (int i = 0; i <= n; ++i) {
            cost[i] = -1;
            used[i] = 0;
        }
        int k = 1, tmp;
        cost[k] = 0;
        while (k) {
            used[k] = 1;
            tmp = 0;
            for (int i = 2; i <= n; ++i) {
                if (used[i]==0) {
                    if (bd[i][k]>0 && cost[i]>(unsigned int)max((unsigned int)bd[i][k], cost[k])) {
                        cost[i] = max((unsigned int)bd[i][k], cost[k]);
                    }
                    if (cost[i] < cost[tmp]) tmp = i;
                }
            }
            k = tmp;
        }
        if (cost[n] == -1) {
            printf("-1\n");
        } else {
            printf("%d\n", cost[n]);
        }
    }
    return 0;
}
*/
