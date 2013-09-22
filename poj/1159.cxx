#include <cstdio>

#define MAX_LEN 5001
char buf[MAX_LEN];
int b[2][MAX_LEN];

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	int n, i, j;
	scanf("%d\n%s", &n, buf);
	for (i=n-1; i>=0; i--) {
		for (j=i; j<n; j++) {
			if (buf[i] == buf[j]) {
				b[i%2][j] = b[1-i%2][j-1];
			} else {
				b[i%2][j] = b[i%2][j-1]<=b[1-i%2][j] ?\
					b[i%2][j-1]:b[1-i%2][j];
				b[i%2][j]++;
			}
		}
	}
	printf("%d\n", b[0][n-1]);
	return 0;
}