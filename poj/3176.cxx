#include <cstdio>

#define MAX_N 350

int buf[MAX_N][MAX_N];

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	int n, tmp;
	scanf("%d\n", &n);
	scanf("%d", buf[0]+1);
	for (int i=1; i<n; i++) {
		for (int j=1; j<=i+1; j++) {
			scanf("%d", buf[i]+j);
			buf[i][j] += buf[i-1][j-1]>buf[i-1][j] ? buf[i-1][j-1]:buf[i-1][j];
		}
	}	

	tmp = 0;
	for (int i=1; i<=n; i++) {
		if (tmp < buf[n-1][i]) {
			tmp = buf[n-1][i];
		}
	}
	printf("%d\n", tmp);

	return 0;
}