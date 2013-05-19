#include <cstdio>

char buf[10];
int n;


void multi(char *a, int b) {
    int n = a[0];
    long long carry = 0;

    int i;
    for (i=1; i<=n; ++i) {
       carry += a[i] * b;
       a[i] = carry % 10;
       carry /= 10;
    }
    while (carry) {
       a[i++] = carry % 10;
       carry /= 10;
    }
    a[0] = i - 1;
}

char as[600];
int main(void) {
    while (scanf("%s %d", buf, &n) != EOF) {
        // trans to r * 1/10**(point)
        int r=0, point=0;
        char *ch = buf;
        while (*ch) {
            if (*ch == '.') {
                point = 1;
            } else {
               r *= 10;
               r += *ch - '0';
               if (point) ++point;
            }
            ++ch;
        }
        --point; 
        while (!(r % 10)) {
            r /= 10;
            --point;
        }
        //printf("%d, %d, %d\n", r, point, n);
        as[0] = 1;
        as[1] = 1;
        for (int i=0; i<n; ++i) {
            multi(as, r);
        }
        point *= n;
        int head = as[0] - point;
        if (head <= 0) {
            putchar('.');
            while (head) {
               putchar('0'); 
               ++head;
            }
            for (int i=as[0]; i>=1; --i) {
                putchar(as[i] + '0');
            }
        }else if (point>0) {
            for (int i=as[0]; i>=1; --i) {
                if (i == point) putchar('.');
                putchar(as[i]+'0');
            }
        }else{
           for (int i=as[0]; i>=1; --i) {
               putchar(as[i]+'0');
           }
           while (point) {
               putchar('0');
               ++point;
           }
        }
        putchar('\n'); 
    }
   return 0; 
}
