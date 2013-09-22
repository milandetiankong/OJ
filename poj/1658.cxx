#include <cstdio>

int main(void) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b, c, d, e;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (a+c==2*b && b+d == 2*c) {
			e = 2*d - c;
		} else {
			e = d*d/c;	
		}
		printf("%d %d %d %d %d\n", a, b, c, d, e);
	}

}