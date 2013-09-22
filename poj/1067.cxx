#include <cstdio>
#include <cmath>


int main(void) {
	int a, b, k;
	while (scanf("%d %d", &a, &b) != EOF) {
		if (a>b) {
			k = a -b;
			a = b;
		} else {
			k = b - a;
		}
		b = 0.5*k*(sqrt(5.0) + 1.0);
		if ( a == b) {	
			printf("0\n");
		} else {
			printf("1\n");
		}
	}
}