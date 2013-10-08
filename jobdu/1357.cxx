#include <stdio.h>
#include <math.h>

typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ll n, a, ret;
    while (scanf("%lld", &n) != EOF) {
        a = 8*n + 1;
        a = sqrt(a);
        if (a*a == 8*n + 1) ret = (a-1)/2;
        else ret = (a-1)/2 + 1;
        printf("%lld\n", ret);
    }

    return 0;
}

