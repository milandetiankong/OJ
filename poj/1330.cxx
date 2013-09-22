#include <cstdio>

int t, n;

int buf[10003];
int yes[10003];

int pre, p;

int solve(int a, int b) {
	int ss = a;
	int ans = 0;
	while (ss) {
		yes[ss] = 1;
		ss = buf[ss];
	}
	ss = b;
	while (ss) {
		if (yes[ss]) {
			ans = ss;
			break;
		}
		ss = buf[ss];
	}
	ss = a;
	while (ss) {
		yes[ss] = 0;
		ss = buf[ss];
	}
	return ans;
}

int main(void) {
	scanf("%d", &t);
	for (int i=0; i<t; ++i) {
		scanf("%d", &n);

		for (int j=1; j<n; ++j) {
			scanf("%d %d", &pre, &p);
			buf[p] = pre;
		}

		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", solve(a, b));
		for (int j=0; j<10003; ++j) {
			buf[j] = 0;
		}
	}
}