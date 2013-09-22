#include <cstdio>

int buf[10005];

#define MAX 10000


int main(void) {
	for (int i=1; i<=MAX; ++i) {
		int r = i;
		int g = i;
		while (r) {
			g += r%10;
			r /= 10;
		}
		if (g<=MAX) {
			buf[g] = 1;
		}
	}

	for (int i=1; i<=MAX; ++i) {
		if (buf[i]==0) {
			printf("%d\n", i);
		}
	}
}