#include <stdio.h>
 
char buf[1000006];
 
int main(void) {
    while (scanf("%s", buf) != EOF) {
        int i, sum = 0, del = 0;
        for (i = 0; buf[i]; ++i) {
            if (buf[i] == '(') {
                ++sum;
            } else {
                if (sum) {
                    --sum;
                } else { 
                    ++del;
                }
            }
        }
        printf("%d\n", i - del - sum);
    }
    return 0;
}
