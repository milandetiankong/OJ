#include <cstdio>

int n;
int buf[102];
int deep;

bool dfs(int rem) {
	if (deep==100) {
		return false;
	}
	if (rem==0) {
		return true;
	}
	buf[deep++]=0;
	if(dfs((10*rem)%n)) {
		return true;
	}
	deep--;

	buf[deep++]=1;
	if(dfs((10*rem+1)%n)) {
		return true;
	}
	deep--;

	return false;
}

void print() {
	for (int j=0; j<deep; j++) {
		printf("%d", buf[j]);
	}
	printf("\n");
}

int main()
{
	//freopen("in.txt", "r", stdin);
	while (scanf("%d", &n), n) {
		buf[0]=1;
		deep = 1;
		dfs(1);
		print();
	}
	return 0;
}