#include <cstdio>

int main(int argc, char const *argv[])
{
	int t, ti, n, sum;
	scanf("%d", &t);
	ti = 0;
	while (ti++ < t) {
		scanf("%d", &n);
		sum = 0;
		while (n) {
			n /= 5;
			sum += n;
		}
		printf("%d\n", sum);
	}
	return 0;
}