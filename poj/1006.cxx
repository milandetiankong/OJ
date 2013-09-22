#include <cstdio>

int main(int argc, char const *argv[])
{
    //freopen("in.txt", "r", stdin);
    int p, e, i, d, j;
    j = 1;
    while (scanf("%d %d %d %d\n", &p, &e, &i, &d), p!=-1) {
        p %= 23; //5544
        e %= 28; //14421
        i %= 33; //1288
        int t = ((long long)p*5544 + e*14421 + i*1288)%(23*28*33);
        if (t > d) {
            t -= d;
        } else {
            t = t + (23*28*33) - d;
        }
        printf("Case %d: the next triple peak occurs in %d days.\n", j++, t);
    }
    return 0;
}