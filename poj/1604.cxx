#include <cstdio>

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	int sum, n, r;
	while (scanf("%d", &n) != EOF) {
		sum = -n;
		if (n >= 9) {
			r = 6;
		} else {
			r = 1;
		}
		for (int k=n; k; k/=5) {
			sum += k;
			for (int i=k%10; i; i--) {
				if (i!=5) {
					r *= i;
					r %= 10;
				}
			}
		}
		for (int i=sum%4; i; i--) {
			r /= 2;
			if (r&1) {
				r += 5;
			}
		}
		printf("%5d -> %d\n", n, r);
	}
	return 0;
}