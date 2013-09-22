#include <cstdio>

#define N 5

int queue[N*N];
int front;
int rear;

bool visit[N*N];
int fa[N*N];
int X[4] = {-1, 0, +1, 0};
int Y[4] = {0, +1, 0, -1};


void bfs(int s) {
	queue[rear++] = s;
	visit[s] = 1;
	fa[s] = s;
	int cur;
	int next;
	int x, y;
	while (front<rear) {
		cur = queue[front++];
		for (int i=0; i<4; i++) {
			x = cur/N + X[i];
			y = cur%N + Y[i];
			next = x*N + y;
			if (x>=0 && x<N && y>=0 && y<N && visit[next]==0) {
				visit[next] = 1;
				fa[next] = cur;
				queue[rear++] = next;
			}
		}
	}
}

void print(int end) {
	int cur = end;
	int tmp;
	int pre=cur;
	cur = fa[cur];
	while (fa[cur] != cur) {
		tmp = fa[cur];
		fa[cur] = pre;
		pre = cur;
		cur = tmp;
	}
	cur = pre;
	printf("(0, 0)\n");
	while (cur != end) {
		printf("(%d, %d)\n", cur/N, cur%N);
		cur = fa[cur];
	}
	printf("(%d, %d)\n", cur/N, cur%N);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			scanf("%d", &visit[i*N+j]);
		}
	}
	bfs(0);
	print(N*N-1);
}