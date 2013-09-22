#include <cstdio>

int n;
int sum;
char buf[20];

int past;

void print() {
	for (int ni=1; ni<n; ni++) {
		printf("%d %c ", ni, buf[ni]);
	}
	printf("%d\n", n);
}

void dfs(int x, int past, int cur, int pre) {
	if (x==n) {
		if (cur==0) {
			if (sum<20) {
				print();
			}
			sum++;
		}
		return ;
	}


	buf[x] = '+';
	dfs(x+1, x+1, cur+x+1, cur);

	buf[x] = '-';
	dfs(x+1, -x-1, cur-x-1, cur);

	buf[x] = '.';

	if (past>=0) {
		if (x+1>9){
			past *= 10;
		}
		past *= 10;
		past += x+1;
	} else {
		if (x+1>9) {
			past *= 10;
		}
		past *= 10;
		past -= (x+1);
	}

	dfs(x+1, past, pre+past, pre);

}

int main()
{
	//freopen("in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		sum = 0;
		past=1;
		dfs(1, 1, 1, 0);	
		printf("%d\n", sum);
	}
	return 0;
}