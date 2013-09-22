#include <cstdio>

int main(int argc, char const *argv[])
{
    //freopen("in.txt", "r", stdin);
    double sum, tmp;
    sum = 0.0;
    for (int i=0; i<12; i++) {
        scanf("%lf", &tmp);
        sum += tmp;
    }
    printf("$%.2f\n", sum/12.0);
    return 0;
}