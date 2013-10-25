#include <stdio.h>

char buf[100005];
int main(void) {
    int n;
    while (scanf("%d", &n)!=EOF &&  n) {
        gets(buf);
        int j = 0;
        while ((buf[j]=getchar()) != '\n') ++j;
        buf[j] = 0;
        buf[n] = 0;
        char *p = buf;
        j = 1;
        while (*++p) {
            if (' '==*p && ' '==*(p-1)) continue;
            buf[j++] = *p;
        }
        int k;
        for (int i = 0; i < j; ++i) {
            if  (' ' == buf[i]) {
                k = i-1;
                while (k>=0 && ' '!=buf[k]) putchar(buf[k--]);
                putchar(' ');
            }
        }
        if (buf[j-1] != ' ') {
            k = j-1;
            while (k>=0 && ' '!=buf[k]) {
                putchar(buf[k--]);
            }
        }
        putchar('\n');
    }
    return 0;
}
