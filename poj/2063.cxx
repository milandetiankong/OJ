#include <cstdio>
#include <cstring>
#include <cmath>


int f[45000];


int main(void) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int am, y;
		int d;
		scanf("%d %d %d", &am, &y, &d);
		int m = pow(1.1, y) * am / 1000;
		memset(f+1, 0, sizeof(int)*m);
		for (int i=0; i<d; ++i) {
			int v, in;
			scanf("%d %d", &v, &in);
			v /= 1000;
			for (int j=v; j<=m; ++j) {
				if (f[j-v] + in > f[j]) {
					f[j] = f[j-v] + in;
				}
			}
		}
		//print
		/*
		for (int i=0; i<=m; ++i) {
			printf("%d ", f[i]);
		}
		printf("\n");
		*/
		int max = am;
		for (int i=0; i<y; ++i) {
			max += f[max/1000];
		}	
		printf("%d\n", max);
	}
}