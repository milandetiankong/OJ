#include <cstdio>

#define PI 3.1415926535

int main(int argc, char const *argv[])
{
    //freopen("in.txt", "r", stdin);
    double x, y;
    int n, i;
    scanf("%d", &n);
    i = 1;
    while (i <= n) {
        scanf("%lf %lf", &x, &y);
        printf("Property %d: This property will begin eroding in year %d.\n",
            i, (int)(PI*(x*x + y*y) / 100.0) + 1);
        i++;
    }
    printf("END OF OUTPUT.\n");
    return 0;
}