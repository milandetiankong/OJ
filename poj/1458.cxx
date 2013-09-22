#include <cstdio>
#include <cstring>


#define MAX_LEN 256

//char c[MAX_LEN][MAX_LEN];
int  b[MAX_LEN][MAX_LEN];
char sn[MAX_LEN];
char sm[MAX_LEN];

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	int n, m;
	while (scanf("%s %s", sn, sm) != EOF) {
		n = strlen(sn);
		m = strlen(sm);	
		for (int i=0; i<n; i++) {
			b[i][0] = 0;
		}
		for (int i=0; i<m; i++) {
			b[0][i] = 0;
		}

		for (int i=1; i<=n; i++) {
			for (int j=1; j<=m; j++) {
				if (sn[i-1] == sm[j-1]) {
					//c[i][j] = '*'; //
					b[i][j] = 1 + b[i-1][j-1];
				} else if (b[i-1][j] >= b[i][j-1]){
					//c[i][j] = '|'; // up
					b[i][j] = b[i-1][j];
				} else {
					//c[i][j] = '-'; //left
					b[i][j] = b[i][j-1];
				}
			}
		}
		printf("%d\n", b[n][m]);
	}
	return 0;
}