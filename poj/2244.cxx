#include <cstdio>

int solve(int n) {
	int m = 2;

	while (true) {
		int st = 1;
		int cur = n;
		int newst;
		while (true) {
			newst = (cur-st)%m;
			cur -= (cur-st)/m + 1;
			st = m - newst;
			if (1 == cur) {
				return m;
			}
			if (st > cur) {
				st = (st-1)%cur +1;
			}
			if (1 == st) {
				break;
			}
		}
		++m;
	}
	return m;
}

int main(void) {
	int n;
	while (scanf("%d", &n), n) {
		printf("%d\n", solve(n));
	}
	return 0;
}