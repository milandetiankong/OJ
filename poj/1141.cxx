#include <cstdio>
#include <cstring>

#define INF (~(1<<31)) 

char s[101];
int f[100][100];
int r[100][100];


void print(int i, int j) {
	if (i > j) {
		return ;
	}
	if (i == j)	{
		if (s[i] == '[' || s[i] == ']') {
			printf("[]");
		} else {
			printf("()");
		}
		return ;
	}
	if (r[i][j] == -1) {
		printf("%c", s[i]);
		print(i+1, j-1);
		printf("%c", s[j]);
	} else {
		print(i, r[i][j]);
		print(r[i][j] + 1, j);
	}
}
int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);

	while(gets(s)){
		int len = 0;
		int i, j;
		while (s[len]) {
			++len;
		}
		memset(f, 0, sizeof(f));
		memset(r, 0, sizeof(r));
		for (i=len-1; i>=0; i--) {
			for (j=i; j<len; j++) {
				f[i][j] = INF;
				if (i == j) {
					f[i][j] = 1;
					continue;
				}
				if (s[i]=='[' && s[j]==']') {
					f[i][j] = f[i+1][j-1];
					r[i][j] = -1;
				} else if (s[i]=='(' && s[j]==')') {
					f[i][j] = f[i+1][j-1];
					r[i][j] = -1;
				}

				for (int k=i; k<j; k++) {
					int tmp = f[i][k] + f[k+1][j];
					if (f[i][j] > tmp) {
						f[i][j] = tmp;
						r[i][j] = k;
					}	
				}
			}
		}
		print(0, len-1);
		printf("\n");
	}
	return 0;
}