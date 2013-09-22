#include <cstdio>

int k;

int ready[20];

int isok(int n) {
	int di = n;
	int len = 2*k;
	
	while (len!=k) {
		di = (di-1)%len + 1;
		if (di<=k) {
			return 1;
		}
		--len;
		--di;
		di += n;
		//printf("%d %d %d\n", len, n, di);
		//scanf("%*d");
	}
	return 0;
}

int solve() {
	if (ready[k]) {
		return ready[k];
	}
	int n = k+1;
	while (isok(n)) {
		++n;
	}
	ready[k] = n;
	return n;
}


int main(void) {
	while (scanf("%d", &k), k) {
		printf("%d\n", solve());
	}
}