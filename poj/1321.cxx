#include <cstdio>

bool map[9][9];

int n, k;

int result[9];
int sum;

bool col[9];

//xi had placed //x row
void dfs(int x, int xi) {
	if (xi==k) {
		sum++;
		return;
	}
	if (x==n) {
		return;
	}

	result[x]=0;
	dfs(x+1, xi);

	for (int i=1; i<=n; i++) {
		if (map[x][i-1] && col[i-1]==false) {
			result[x] = i;
			col[i-1] = true;
			dfs(x+1, xi+1);
			col[i-1] = false;
		}
	}

}

char tmp[20];

int main()
{
	//freopen("in.txt", "r", stdin);
	while (scanf("%d %d", &n, &k), n != -1) {
		sum = 0;
		for (int i=0; i<n; i++) {
			scanf("%s", tmp);
			for (int j=0; j<n; j++) {
				if ('#' == tmp[j]) {
					map[i][j] = true;
				}else {
					map[i][j] = false;
				}
			}
			scanf("\n");
		}
		dfs(0, 0);
		printf("%d\n", sum);

	}
	return 0;
}