#include <cstdio>
#include <algorithm>

int r, c;

typedef struct Node {
	int x, y;
	int h;
	bool operator<(const Node &b) const{
		return (h<b.h);
	}
}Node;

Node map[12100];

int ht[110][110];
int step[110][110];

int dir[4][2] = {{0, -1}, {1, 0}, {-1, 0}, {0, 1}};

int main(void) {
	scanf("%d %d", &r, &c);
	int n=0;
	for (int i=0; i<r; ++i) {
		for (int j=0; j<c; ++j) {
			scanf("%d", ht[i] + j);
			map[n].x = i;
			map[n].y = j;
			map[n++].h = ht[i][j];	
		}
	}
	std::sort(map, map+n);

	
	int xx, yy;
	int max = -1;
	for (int i=0; i<n; ++i) {
		int &tmp = step[map[i].x][map[i].y];
		for (int k=0; k<4; ++k) {
			xx = map[i].x + dir[k][0];
			yy = map[i].y + dir[k][1];
			if (xx>=0 && xx<r && yy>=0 && yy<c && ht[xx][yy]<map[i].h && step[xx][yy]+1>tmp) {	
				tmp = step[xx][yy]+1;
			}
		}
		if (tmp>max) {
			max = tmp;
		}
	}
	printf("%d\n", max+1);
}
