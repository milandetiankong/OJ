#include <cstdio>

int buf[2][100];

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	int n, tmp;
	int x=0;
	int y=1;
	scanf("%d\n", &n);
	for (int i=0; i<n; i++) {
		for (int j=0; j<=i; j++) {
			scanf("%d", &tmp);
			buf[x][j] = tmp;
		}
		if (i>0) {
			buf[x][0] += buf[y][0];	
			for (int j=1; j<i; j++){
				buf[x][j] += (buf[y][j-1]>buf[y][j] ? buf[y][j-1]:buf[y][j]);
			}
			buf[x][i] += buf[y][i-1];
		}

		x = y;
		y = 1- x;
	}
	for (int i=1; i<n; i++) {
		if (buf[y][0]<buf[y][i]){
			buf[y][0] = buf[y][i];
		}
	}
	printf("%d\n", buf[y][0]);
	return 0;
}