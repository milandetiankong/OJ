#include <cstdio>

int r[50010];
int f[50010];
int n, k;

int find(int x) {
	if (x == r[x]) {
		return x;
	}
	int dx = find(r[x]);
	f[x] = 	(f[r[x]] + f[x]) % 3;
	r[x] = dx;
	return dx;
}

int main(void) {
	//cin >> n >> k;
	scanf("%d %d", &n, &k);
	for (int i=1; i<=n; ++i) {
		r[i] = i;
		f[i] = 0;
	}
	int d, x, y;
	int fs = 0;

	int rx, ry;
	while (k--) {
		//cin >> d >> x >> y;
		scanf("%d %d %d", &d, &x, &y);
		if (x>n || y>n) {
			++fs;
			continue;
		}
		--d;
		rx = find(x);
		ry = find(y);	
		if (rx == ry) {
			if ( (d+f[y])%3 != f[x]) {
				++fs;
			}
		} else {
			r[rx] = ry;
			f[rx] = (d - f[x] + f[y] +3)%3;
		}	
	}
	//cout << fs << endl;
	printf("%d\n", fs);
}