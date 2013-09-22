#include <cstdio>


int buf[15];
int k;
bool map[15];

void print() {
	int i=0;
	while(!map[i++]) ;
	printf("%d", buf[i-1]);	
	for (; i<k; i++) {
		if (map[i]) {
			printf(" %d", buf[i]);
		}
	}
	printf("\n");
}
void dfs(int x, int xi) {
	//printf("dfs:%d %d\n", x, xi);
	if (xi==6) {
		print();
		return;
	}
	if (x==k) {
		return;
	}	
	map[x] = true;
	dfs(x+1, xi+1);
	map[x] = false;

	dfs(x+1, xi);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	while (scanf("%d", &k), k) {
		for (int i=0; i<k; i++) {
			scanf("%d", buf+i);
		}
		dfs(0, 0);
		printf("\n");
	}
	return 0;
}