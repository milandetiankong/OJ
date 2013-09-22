#include <cstdio>


int c[100010];
int r[100010];
int f[100010];

int n, m;

int find(int x) {
	if (x != f[x]) {
		int rx = find(f[x]);
		r[x] = (r[x] + r[f[x]])%2;
		f[x] = rx;
	}
	return f[x];
}

void uni(int a, int b) {
	int ra = find(a);
	int rb = find(b);

	if (ra==rb) {
		return ;
	}
	if (c[a] > c[b]) {
		f[rb] = ra;
		r[rb] = (r[a] + r[b] + 1)%2;
		c[ra] = c[ra] + c[rb];
	} else {
		f[ra] = rb;
		r[ra] = (r[a] + r[b] + 1)%2;
		c[rb] = c[ra] + c[rb];
	}
}

int main(void) {
	int t;
	scanf("%d", &t);
	char type[10];
	int a, b;
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i=1; i<=n; ++i) {
			f[i] = i;
			c[i] = 1;
			r[i] = 0;
		}	
		while (m--) {
			scanf("%s %d %d", type, &a, &b);
			if (type[0] == 'D') {
				uni(a, b);
			} else {
				int ra = find(a);
				int rb = find(b);

				if (ra != rb) {
					printf("Not sure yet.\n");
				}else if (r[a] == r[b]) {
					printf("In the same gang.\n");
				} else {
					printf("In different gangs.\n");
				}
			}

		}

	}
}