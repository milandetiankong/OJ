#include <cstdio>


#define MAX_N  1500

int x2, x3, x5;
int buf[MAX_N] = {1};


int min(int xx2, int xx3, int xx5) {
	int m = xx2;
	if (xx3 < m) {
		m = xx3;
	}
	if (xx5 < m) {
		m = xx5;
	}

	if (m == xx2) {
		x2++;
	}
	if (m == xx3) {
		x3++;
	}
	if (m == xx5) {
		x5++;
	}

	return m;
}

int main(void) {
	int n;

	for (int i=1; i<MAX_N; ++i) {
		buf[i] = min(buf[x2]*2, buf[x3]*3, buf[x5]*5);
	}

	while (scanf("%d", &n), n) {
		printf("%d\n", buf[n-1]);
	}
	return 0;
}