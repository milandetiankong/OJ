#include <cstdio>


int reversed(int a) {
	int b = 0;
	for (; a>0; a/=10) {
		b *= 10;
		b += a%10;
	}
	return b;
}

int main(void) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		a = reversed(a);
		b = reversed(b);
		printf("%d\n", reversed(a+b));
	}

}