#include <stdio.h>

int main(void) {
    double max;
    double tmp;
    double ret = 0.65;
    char f;
    for (int i = 0; i < 3; ++i) {
        scanf("%lf", &max);
        f = 'W';
        scanf("%lf", &tmp);
        if (max < tmp) {
            f = 'T';
            max = tmp;
        }
        scanf("%lf", &tmp);
        if (max < tmp) {
            f = 'L';
            max = tmp;
        }
        printf("%c ", f);
        ret *= max;
    }
    printf("%.2lf\n", (ret-1.0)*2);
}
