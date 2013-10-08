#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    while (scanf("%d", &n) != EOF) {
        double ret = -100000;
        double crt = 1;
        double _crt = 1;
        double tmp;
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &tmp);
            crt *= tmp; _crt *= tmp; if (ret < crt) ret = crt;
            if (ret < _crt) ret = _crt;
            double a = max(crt, _crt);
            double b = min(crt, _crt);
            if (a > 1.0) crt = a;
            else  crt = 1;
            if (b < 0) _crt = b;
            else _crt = a;
        }
        if (ret >= 0) {
            int x = ret * 100;
            if (x % 100)
            printf("%.2lf\n", ret);
            else printf("%d\n", x/100);
        }
        else printf("-1\n");
    }
    return 0;
}
