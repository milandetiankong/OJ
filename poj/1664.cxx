#include <cstdio>


int sum;
int m,n;
void dfs(int min, int len, int x) {
	if (len==n) {
		return;
	}
	for (int i=min; i<=x/2; ++i) {
		++sum;
		dfs(i, len+1, x-i);
	}
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &m, &n);
		sum = 0;
		dfs(1, 1, m);
		printf("%d\n", sum+1);
	}

}