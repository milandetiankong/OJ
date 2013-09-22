#include <cstdio>


int row, col;

bool map[50][50][4];
bool v[50][50];

int dfs(int i, int j) {
	if (i<0 || j<0 || i>=row || j>=col) {
		return 0;
	}
	if (v[i][j]) {
		return 0;
	}
	int max = 1;
	v[i][j] = true;

	if (map[i][j][0]==false) {
		max += dfs(i, j-1);
	}
	if (map[i][j][1]==false) {
		max += dfs(i-1, j);
	}
	if (map[i][j][2]==false) {
		max += dfs(i, j+1);
		
	}
	if (map[i][j][3]==false) {
		max += dfs(i+1, j);
	}
	return max;
}

int main()
{
	int tmp;
	//freopen("in.txt", "r", stdin);
	while (scanf("%d%d", &row, &col) != EOF) {
		for (int i=0; i<row; i++) {
			for (int j=0; j<col; j++) {
				scanf("%d", &tmp);
				map[i][j][0] = tmp&1;
				tmp >>= 1;
				map[i][j][1] = tmp&1;
				tmp >>= 1;
				map[i][j][2] = tmp&1;
				tmp >>= 1;
				map[i][j][3] = tmp&1;
				v[i][j] = false;	
			}
		}
		int sum = 0;
		int max = 0;
		for (int i=0; i<row; i++) {
			for (int j=0; j<col; j++) {
				if (v[i][j]==false) {
					tmp = dfs(i, j);
					if (tmp > max) {
						max = tmp;
					}
					sum++;
				}
			}
		}
		printf("%d\n%d\n", sum, max);

	}
	
	return 0;
}