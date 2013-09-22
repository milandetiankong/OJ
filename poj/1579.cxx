#include <cstdio>


int f[21][21][21];

int get(int a, int b, int c) {
	if (a<=0 || b<=0 || c<=0) {
		return 1;
	}
	if (a >20 || b>20 || c>20) {
		return get(20, 20, 20);
	}
	//  0<a, b, c <=20
	if (f[a][b][c]) {
		return f[a][b][c];
	}

	if (a<b && b<c) {
		f[a][b][c] = get(a, b, c-1) + get(a, b-1, c-1) - get(a, b-1, c);
	} else {
		f[a][b][c] = get(a-1, b, c) + get(a-1, b-1, c) + get(a-1, b, c-1) - get(a-1, b-1, c-1);
	}

	return f[a][b][c];
}

int main(void) {
	int a, b, c;
	while (scanf("%d %d %d", &a, &b, &c), !(a==-1 && b==-1 && c==-1)) {
		printf("w(%d, %d, %d) = %d\n", a, b, c, get(a, b, c));
	}
}