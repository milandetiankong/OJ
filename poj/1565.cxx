#include <cstdio>

char buf[100];

int main(void) {
	while (scanf("%s", buf), buf[0]-'0') {
		int len=0;
		while (buf[len]) {
			buf[len] -= '0';
			++len;
		}
		int sum = 0;
		int k=2;
		for (int i=len-1; i>=0; --i) {
			sum += buf[i]*(k-1);
			k *= 2;
		}
		printf("%d\n", sum);
	}

}