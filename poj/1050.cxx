#include <cstdio>


#define MAX_N 100

int buf[MAX_N];

char r[MAX_N][MAX_N];
int ans;

void maxSub(int n) {
	int max = 0;

	for (int i=0; i<n; ++i) {
		max += buf[i];
		if (max < 0) {
			max = 0;
		} else if (ans < max) {
			ans = max;
		}
	}
}


int main(void) {
	int n;
	int tmp;
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			scanf("%d", &tmp);
			r[i][j] = tmp;
		}
	}

	for (int sline = 0; sline < n; ++sline) {
		for (int i=0; i<n; ++i) {
			buf[i] = r[sline][i];	
		}
		maxSub(n);

		for (int eline = sline+1; eline < n; ++eline) {
			for ( int i=0; i<n; ++i) {
				buf[i] += r[eline][i];
			}
			maxSub(n);

		}
	}

	printf("%d\n", ans);

	return 0;
}