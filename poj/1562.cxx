#include <cstdio>

int m, n;
char buf[101][101];


int dfs(int mi, int ni) {
	if (mi<0 || ni<0 || mi>=m || ni>=n)	{
		return 0;
	}
	if (buf[mi][ni]=='*') {
		return 0;
	}
	int cnt = 1;
	buf[mi][ni] = '*';

	cnt += dfs(mi, ni-1);
	cnt += dfs(mi, ni+1);
	cnt += dfs(mi-1, ni-1);
	cnt += dfs(mi-1, ni+1);
	cnt += dfs(mi+1, ni-1);
	cnt += dfs(mi+1, ni+1);
	cnt += dfs(mi-1, ni);
	cnt += dfs(mi+1, ni);

	return cnt;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	while (scanf("%d %d", &m, &n), m) {
		int sum = 0;
		for (int mi=0; mi<m; mi++) {
			scanf("%s", buf[mi]);		
		}
		for (int mi=0; mi<m; mi++) {
			for (int ni=0; ni<n; ni++) {
				if (buf[mi][ni]=='@') {
					dfs(mi, ni);
					sum++;
				}
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}