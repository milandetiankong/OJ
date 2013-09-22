#include <cstdio>
#include <cstring>

char buf[10][21];

int map[10][10];

int n;


int comb(int i, int j) {
	int ni = strlen(buf[i]);
	int nj = strlen(buf[j]);
	int x = ni>nj? nj: ni;
	int max=0;
	for (int xi=1; xi<=x; xi++) {
		int xj=0;
		int k;
		for (k=xi; k; k--) {
			if (buf[i][ni-k] != buf[j][xj++]) {
				break;
			}
		}
		if (k==0) {
			if (xi>max) {
				max = xi;
			}
		}
	}
	return nj - max;
}
bool v[10];
int min;
void dfs(int x, int len, int pre) {
	if (len >= min) {
		return;
	}
	if (x==n) {
		min = len;
		return;
	}
	for (int ni=0; ni<n; ni++) {
		if (v[ni]==true) {
			continue;
		}
		v[ni] = true;
		dfs(x+1, len + map[pre][ni], ni);
		v[ni] = false;
	}

}
int main()
{
	//freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int ni=0; ni<n; ni++) {
			scanf("%s", buf[ni]);
		}
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				map[i][j] = comb(i, j);
				map[j][i] = comb(j, i);
				//printf("%s %s == %d %d\n", buf[i], buf[j], map[i][j], map[j][i]);
			}
		}
		min = ~(1<<31);
		for (int ni=0; ni<n; ni++) {
			v[ni] = true;
			dfs(1, strlen(buf[ni]), ni);
			v[ni] = false;
		}
		printf("%d\n", min);

	}
	return 0;
}