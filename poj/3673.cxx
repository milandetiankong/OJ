#include <cstdio>


int main(void) {
	int a, b;
	int suma = 0;
	int ans = 0;
	scanf("%d %d", &a, &b);
	while (a) {
		suma += a%10;
		a /= 10;
	}

	while (b) {
		ans += (b%10) * suma;
		b /= 10;
	}

	printf("%d\n", ans);

	return 0;
}