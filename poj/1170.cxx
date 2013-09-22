#include <cstdio>
#include <cstring>



#define MAX_N  6


int max[MAX_N][MAX_N][MAX_N][MAX_N][MAX_N];
int cur[MAX_N];
int mcode[1010];

int k[MAX_N];
int p[MAX_N];

int sum;

int main(void) {
	int b, tmp, s;
	scanf("%d", &b);
	sum = 0;
	for (int i=0; i<b; ++i) {
		scanf("%d %d %d", &tmp, k+i, p+i);
		mcode[tmp] = i;
		sum += k[i]*p[i];
	}

	scanf("%d", &s);

	int n;
	int v;
	for (int i=0; i<s; ++i) {
		scanf("%d", &n);

		memset(cur, 0, sizeof(cur));
		for (int j=0; j<n; ++j) {
			scanf("%d", &tmp);
			scanf("%d", cur+mcode[tmp]);
		}

		scanf("%d", &v);

		tmp = 0;
		for (int i=0; i<b; ++i) {	
			tmp += cur[i]*p[i];
		}
		v = tmp - v;

		for (int a0=cur[0]; a0<=k[0]; ++a0) {
			for (int a1=cur[1]; a1<=k[1]; ++a1) {
				for (int a2=cur[2]; a2<=k[2]; ++a2) {
					for (int a3=cur[3]; a3<=k[3]; ++a3) {
						for (int a4=cur[4]; a4<=k[4]; ++a4) {
							tmp = max[a0-cur[0]][a1-cur[1]][a2-cur[2]][a3-cur[3]][a4-cur[4]] + v;	
							if (max[a0][a1][a2][a3][a4] < tmp) {
								max[a0][a1][a2][a3][a4] = tmp;
							}	
						}
					}
				}
			}
		}
	}

	printf("%d\n", sum - max[k[0]][k[1]][k[2]][k[3]][k[4]]);

	return 0;
}