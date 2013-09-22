#include <cstdio>

int n;
int nn;

char map[5][5];


int max=0;

bool check(int xy) {
	int x = xy/n;
	int y = xy%n;
	if (map[x][y] != '.') {
		return false;
	}

	for (int xi=x; xi>=0 && map[xi][y] != 'X'; xi--) {
		if (map[xi][y]=='O') {
			return false;
		}

	}

	for (int yi=y; yi>=0 && map[x][yi] != 'X'; yi--) {
		if (map[x][yi]=='O') {
			return false;
		}
	}

	return true;
}
void dfs(int xy, int m) {
	if (m>max) {
		max = m;
	}
	if (nn == xy) {
		return ;
	}
	if (nn - xy + m <= max) {
		return;
	}


	int i;
	for (i=xy; xy<nn; xy++) {	
		if (check(xy)) {
			break;
		}
	}
	if (xy==nn) {
		return;
	}
	map[xy/n][xy%n] = 'O';
	dfs(xy+1, m+1);
	map[xy/n][xy%n] = '.';


	dfs(xy+1, m);

}

int main()
{
	//freopen("in.txt", "r", stdin);
	while (scanf("%d", &n), n) {
		nn = n*n;
		for (int ni=0; ni<n; ni++) {
			scanf("%s", map[ni]);
		}
		max = 0;
		dfs(0, 0);
		printf("%d\n", max);
	}

	return 0;
}