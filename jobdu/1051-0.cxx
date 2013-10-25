#include <stdint.h>
#include <iostream>

using namespace std;

uint64_t x, y;
void dfs(uint64_t n) {
    if (n == 0) {
        x = 1; y = 1;
        return ;
    }
    if (n&1) {
        dfs((n-1)>>1);
        y += x;
    } else {
        dfs((n>>1)-1);
        x += y;
    }
}
uint64_t dfs(uint64_t p, uint64_t q) {
    if (p==q && p==1) return 0;
    uint64_t ret;
    if (p < q) {
        ret = dfs(p, q-p);
        ret = (ret<<1) + 1;
    } else {
        ret = dfs(p-q, q);
        ret = (ret+1)<<1;
    }
    return ret;
}
int main(void) {
    int t;
    cin >> t;
    int op;
    uint64_t p, q, n;
    for (int ti = 0; ti < t; ++ti) {
        cin >> op;
        if (1 == op) {
            cin >> n;
            dfs(n-1);
            cout << x << " " << y << endl;
        }
        else {
            cin >> p >> q;
            n = dfs(p, q) + 1;
            cout << n << endl;
        }
    }
}

