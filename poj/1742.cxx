#include <cstdio>
#include <cstring>



int a[101];
int c[101];
bool f[100001];
int used[100001];

int  main(void) {
	int n, m;
	f[0] =  true;
	while (scanf("%d %d", &n, &m), n) {
		int count = 0;
		for (int i=0; i<n; ++i) {
			scanf("%d", a+i);
		}

		for (int i=0; i<n; ++i) {
			scanf("%d", c+i);
		}

		memset(f+1, 0, m*sizeof(bool));

		for (int i=0; i<n; ++i) {
			memset(used+1, 0, m*sizeof(int));
			for (int j=a[i]; j<=m; ++j) {	
				if (!f[j] && f[j-a[i]] && used[j-a[i]]<c[i]) {
					f[j] = true;
					++count;
					used[j] = used[j-a[i]] + 1;
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}