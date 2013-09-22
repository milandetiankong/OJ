#include <cstdio>

int s[1010];

int pop(int top) {
	while (!s[top]) {
		--top;
	}
	return top;
}

int main(void) {
	int n;
	s[0] = 1000000;
	while (scanf("%d", &n), n) {
		int d;
		int i = 1;
		int top = 0;
		while (scanf("%d", &d), d) {
			for (int k=1; k<=n; ++k) {
				s[k] = k;
			}	
			s[d] = 0;
			top = d-1;
			for (int k=2; k<=n; ++k) {
				scanf("%d", &d);
				if (top<0) {
					continue;
				}
				if (d == top) {
					s[d] = 0;
					top = pop(top);
				} else if (d>top) {
					s[d] = 0;
					top = pop(d);
				} else {
					top = -1;
				}
			}

			if (top==0) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
		}
		printf("\n");
	}
}