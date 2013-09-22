#include <cstdio>

#define MAX_N 1000000
bool noPrime[MAX_N];
int main(void) {
	int n;
	noPrime[0] = noPrime[1] = true;

	for (int i=2; i<MAX_N; ++i) {
		if (noPrime[i] == false) {
			for (int j= i+i; j<MAX_N; j+=i) {
				noPrime[j] = true;
			}
		}
	}
	noPrime[2] = true;

	while (scanf("%d", &n), n) {
		for (int i=3; i<=n/2; ++i) {
			if (!noPrime[i] && !noPrime[n-i]) {
				printf("%d = %d + %d\n", n, i, n-i);
				n = 0;
				break;
			}
		}
		if (n) {
			printf("Goldbach's conjecture is wrong.\n");
		}


	}
}