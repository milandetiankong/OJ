#include <cstdio>


int main(void) {
	int n;
	scanf("%d", &n);
	for (int a=6; a<=n; ++a) {
		int sum = a*a*a;
		for (int b=2; b<=a; ++b) {
			int bbb = b*b*b;
			for (int c=b; c<=a; ++c) {
				int ccc = c*c*c;
				for (int d=c; d<=a; ++d) {
					if (sum == d*d*d + bbb +ccc) {
						printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
					}
				}

			}
		}
	}

}