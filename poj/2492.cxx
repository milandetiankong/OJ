#include <cstdio>

int f[4010];

int t, n, k;

int find(int x) {
	if (x != f[x]) {
		f[x] = find(f[x]);
	}
	return f[x];
}


int check(int a, int b) {
	int ra= find(a);
	int rb= find(b);
	if (ra==rb) {
		return 0;
	}

	int ran = find(a+n);
	int rbn = find(b+n);

	f[ra] = rbn;
	f[rb] = ran;
	return 1;
}


int main(void) {	
	scanf("%d", &t);	

	int tt=1;
	while (t--) {
		scanf("%d %d", &n, &k);
		for (int i=1; i<=2*n; ++i) {
			f[i] = i;
		}

		int a, b, ans;
		ans = 1;
		for (int i=0; i<k; ++i) {
			scanf("%d %d", &a, &b);
			if (ans) {
				ans = check(a, b);
			}
		}

		printf("Scenario #%d:\n", tt++);	
		if (ans) {
			printf("No suspicious bugs found!\n");
		} else {
			printf("Suspicious bugs found!\n");
		}
		if (t) {
			printf("\n");
		}
	}

}