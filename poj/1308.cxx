#include <cstdio>


#define N 1001
int r[N];


int find(int x) {
	if (x == r[x]) {
		return x;
	}
	if (r[x] == 0) {
		return 0;
	}
	int rx = find(r[x]);
	r[x] = rx;
	return rx;
}

int main(void) {
	int x, y;
	int rx, ry;
	int k=0;
	while (true) {
		for (int i=1; i<N; ++i) {
			r[i] = 0;
		}
		int ans = 1;
		rx = 0;
		ry = 0;
		while (true) {
			scanf("%d %d", &x, &y);
			if (x+y==0 || x+y == -2) {
				break;
			}

			if (x == y) {
				ans = 0;
			}	

			if (ans) {
				rx = find(x);
				ry = find(y);


				if (ry !=0 && ry !=y) {
					ans = 0;
				} else if (rx !=0 && rx==ry) {
					ans = 0;
				}else if (rx==0) {
					r[x] = x;
					r[y] = x;
				} else {
					r[y] = rx;
				}	
			}
		}

		if (x+y==-2) {
			break;
		}

		if (ans) {
			int tmp=0, root=0;
			for (int i=1; i<N; ++i) {	
				tmp = find(i);
				if (tmp) {
					if (root) {
						if (root != tmp) {
							ans = 0;
							break;
						}
					}
					root = tmp;
				}
			}	
		}

		if (ans) {
			printf("Case %d is a tree.\n", ++k);
		} else {
			printf("Case %d is not a tree.\n", ++k);
		}
	}
}