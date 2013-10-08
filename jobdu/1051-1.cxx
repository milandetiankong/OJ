#include <stdio.h>
#include <stack>
using namespace std;


int buf[100005];
int m[100005];
int n;

void run(void) {
    for (int i = 0; i < n; ++i) {
        scanf("%d", buf+i);
    }
    stack<int> s;
    int i = 0;
    while (i < n) {
        if (s.empty() || buf[s.top()]<=buf[i]) s.push(i++);
        else {
            m[s.top()] = i;
            s.pop();
        }
    }
    while (!s.empty()) {
        m[s.top()] = n+1;
        s.pop();
    }
    int t, l, r, k;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        scanf("%d %d", &l, &r);
        --l; --r;
        while (l <= r) {
            k = l;
            l = m[l];
        }
        printf("%d\n", buf[k]);
    }
}

int main(void) {
    while (scanf("%d", &n) != EOF) {
        run();
    }
}
