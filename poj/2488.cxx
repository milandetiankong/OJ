#include <cstdio>


int p, q;
int map[26][26];
int step;
int end;

char ans[30][2];


int f[8][2] = 
{
	{-2, +1},
	{-2, -1},
	{-1, -2},
	{-1, +2},
	{1, -2},
	{1, +2},
	{2, -1},
	{2, +1}
};

bool dfs(int x, int y) {
	//printf("%d %d %d\n", x, y, step);
	if (step == end) {
		return true;	
	}
	int xi, yi;
	for (int i=0; i<8; i++) {
		xi = x + f[i][0];
		yi = y + f[i][1];
		if (xi>=0 && xi<p && yi>=0 && yi<q && map[xi][yi]==0) {
			map[xi][yi] = ++step;
			if (dfs(xi, yi)) {
				return true;
			}
			step--;
			map[xi][yi] = 0;
		}
	}
	return false;
}
void print() {
	for (int pi=0; pi<p; pi++) {
		for (int qi=0; qi<q; qi++) {
			//printf("%d ", map[pi][qi]);
			ans[map[pi][qi]][0] = pi + 'A';
			ans[map[pi][qi]][1] = qi + '1';
			map[pi][qi] = 0;
		}
		//printf("\n");
	}
	ans[end+1][0] = 0;
	printf("%s\n", ans[1]);
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	for (int ti=0; ti<t; ti++) {
		scanf("%d %d", &q, &p);
		bool flag = false;
		for (int pi=0; pi<p; pi++) {
			for (int qi=0; qi<q; qi++) {
				step = 1;
				end = p*q;
				map[pi][qi] = 1;
				if(dfs(pi, qi)) {
					flag = true;
					break;	
				}
				map[pi][qi] = 0;
			}
			if (flag) {
				break;
			}
		}
		printf("Scenario #%d:\n", ti+1);
		if (flag) {
			print();
		} else {
			printf("impossible\n");
		}
		if (ti<t-1){
			printf("\n");
		}
	}
	return 0;
}