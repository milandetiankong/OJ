#include <cstdio>


int w[3403];
int d[3403];

int max[12881];

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; ++i) {
		scanf("%d %d", w+i, d+i);
	}

	for (int i=0; i<=m; ++i) {
		max[i] = 0;
	}

	for (int i=1; i<=n; ++i) {
		for (int j=m; j>=w[i]; --j) {
			max[j] = max[j]>max[j-w[i]]+d[i]? max[j]:max[j-w[i]]+d[i];
		}
	}
	printf("%d\n", max[m]);

	return 0;
}