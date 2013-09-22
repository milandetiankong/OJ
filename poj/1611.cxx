#include <cstdio>


int c[30010];
int f[30010];
int n, m;


int find(int x) {
	if (x != f[x]) {
		f[x] = find(f[x]);
	}
	return f[x];
}

void uni(int a, int b) {
	int ra = find(a);
	int rb = find(b);
	if (ra==rb) {
		return;
	}

	if (c[ra] > c[rb]) {
		f[rb] =  ra;
		c[ra] += c[rb];
	} else {
		f[ra] = rb;
		c[rb] += c[ra];
	}
}

int main(void) {
	while (scanf("%d %d", &n, &m), n+m) {
		for (int i=0; i<n; ++i) {
			f[i] = i;
			c[i] = 1;
		}
		int k, a, b;
		for (int i=0; i<m; ++i) {
			scanf("%d %d", &k, &a);
			for (int j=1; j<k; ++j) {
				scanf("%d", &b);
				uni(a, b);
				a = b;
			}	
		}
		printf("%d\n", c[find(0)]);
	}

}