#include <cstdio>


#define MAX_N 5843

int x2, x3, x5, x7;
int buf[MAX_N];

int min(int xx2, int xx3, int xx5, int xx7) {
	int m = xx2;
	if (xx3<m) {
		m = xx3;
	}
	if (xx5<m) {
		m = xx5;
	}
	if (xx7<m) {
		m = xx7;
	}


	if (xx2 == m) {
		++x2;
	}
	if (xx3 == m) {
		++x3;
	}
	if (xx5 == m) {
		++x5;
	}
	if (xx7 == m) {
		++x7;
	}
	return m;
}

int main(void) {
	int n;
	int tmp;
	buf[0] = 1;
	for (int i=1; i<MAX_N; ++i) {
		buf[i] = min(buf[x2]*2, buf[x3]*3, buf[x5]*5, buf[x7]*7);
	}

	while (scanf("%d", &n), n) {
		if (11 == n%100 || 12 == n%100 || 13 == n%100) {
			printf("The %dth humble number is ", n);
		} else if (1 == n%10) {
			printf("The %dst humble number is ", n);
		} else if (2 == n%10) {
			printf("The %dnd humble number is ", n);
		} else if (3 == n%10) {
			printf("The %drd humble number is ", n);
		} else {
			printf("The %dth humble number is ", n);
		}
		printf("%d.\n", buf[n-1]);
	}

	return 0;
}