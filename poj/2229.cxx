#include <cstdio>

int f[1000001] = {1,1,2,2};

int dp(int n) {
	for (int j=4; j<=n; ++j) {
		if (j%2) {
			f[j] = f[j-1];
		}else {
			f[j] = f[j-2] + f[j>>1];
			f[j] %= 1000000000;
		}
	}
	return f[n];
}

int main(void) {
	int n;
	scanf("%d", &n);
	printf("%d\n", dp(n));	
}